								if (issafewithdrawConfirmDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) break;
									if (infoDat[0].substr(0, 13) == "safewithdraw_")
									{
										safe_withdrawConfirmCount = infoDat[1];
										if (safe_withdrawConfirmCount.size() > 5) break;
										string coord_and_apos = infoDat[0].erase(0, 13);
										string::size_type pos = coord_and_apos.find('_');
										if (pos != std::string::npos)
										{
											safe_withdrawConfirmCoord = coord_and_apos.substr(0, pos);
											coord_and_apos.erase(0, pos + 1);
											safe_withdrawConfirmApos = coord_and_apos;
										}
										else
										{
											autoBan(peer, false, 24 * 7, "Incorrect parameters issafewithdrawConfirmDialog. Coord and id were: " + coord_and_apos);
											break;
										}
										auto isdbox = std::experimental::filesystem::exists("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safe_withdrawConfirmCoord + ".json");
										if (!isdbox)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting safe vault info.", 0, true);
											break;
										}

										bool contains_non_int3 = !std::regex_match(safe_withdrawConfirmApos, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! issafewithdrawConfirmDialog apos was: " + safe_withdrawConfirmApos);
											break;
										}

										bool contains_non_int4 = !std::regex_match(safe_withdrawConfirmCount, std::regex("^[0-9]+$"));
										if (contains_non_int4 == true)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}
										safe_withdrawConfirmCountInt = atoi(safe_withdrawConfirmCount.c_str());

										safe_withdrawConfirmAposInt = atoi(safe_withdrawConfirmApos.c_str());

										if (safe_withdrawConfirmCountInt < 1 || safe_withdrawConfirmCountInt > 200)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}

										try
										{
											ifstream ifff("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safe_withdrawConfirmCoord + ".json");
											json j;
											ifff >> j;
											ifff.close();

											int itemid = 0;
											bool success = true;

											for (int i = 0; i < 20; i++)
											{
												if (j["safe"][i]["aposition"] == safe_withdrawConfirmAposInt)
												{
													itemid = j["safe"][i]["itemid"];

													if (itemid == 0) break;

													if (safe_withdrawConfirmCountInt > j["safe"][i]["itemcount"])
													{
														Player::OnTextOverlay(peer, "`4Your safe vault does not contains such many.");
														break;
													}

													if (CheckItemExists(peer, j["safe"][i]["itemid"]))
													{
														int currentlyHave = GetQuantityOfItem(peer, j["safe"][i]["itemid"]);
														if (safe_withdrawConfirmCountInt + currentlyHave < 201)
														{
															SaveItemMoreTimes(j["safe"][i]["itemid"], safe_withdrawConfirmCountInt, peer, success);
														}
														else
														{
															Player::OnTextOverlay(peer, "`4You don't have enought space.");
															break;
														}
													}
													else
													{
														if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == static_cast<PlayerInfo*>(peer->data)->currentInventorySize)
														{
															Player::OnTextOverlay(peer, "`4Your inventory is full! You can purchase an inventory upgrade in the shop.");
															break;
														}

														SaveItemMoreTimes(j["safe"][i]["itemid"], safe_withdrawConfirmCountInt, peer, success);
													}

													Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wRemoved " + to_string(safe_withdrawConfirmCountInt) + " " + itemDefs[itemid].name + " from the Safe Vault", 0, true);


													if (j["safe"][i]["itemcount"] == safe_withdrawConfirmCountInt)
													{
														j["safe"][i]["placedby"] = "There was " + to_string(safe_withdrawConfirmCountInt) + " of " + to_string(itemid) + " item, and " + static_cast<PlayerInfo*>(peer->data)->rawName + " withdrawed them.";
														j["safe"][i]["itemid"] = 0;
														j["safe"][i]["itemcount"] = 0;
														j["insafe"] = j["insafe"].get<double>() - 1;
													}
													else
													{
														j["safe"][i]["itemcount"] = j["safe"][i]["itemcount"].get<double>() - safe_withdrawConfirmCountInt;
													}

													ofstream of("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safe_withdrawConfirmCoord + ".json");
													of << j << std::endl;
													of.close();
													break;
												}
											}
										}
										catch (std::exception&)
										{
											SendConsole("safewithdraw_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("safewithdraw_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("safewithdraw_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}
								if (isboxlvl2AddItemDialog)
								{
									if (infoDat[0].substr(0, 15) == "boxlvl2deposit_") boxlvl2AddItemDialog = infoDat[1];
									if (boxlvl1AddItemDialog.size() > 5) break;
									string coord = infoDat[0].substr(15, infoDat[0].length() - 1).c_str();
									int itemid = atoi(boxlvl2AddItemDialog.c_str());


									if (itemid < 1 || itemid > maxItems)
									{
										autoBan(peer, false, 24 * 7, "Proxy detect! In isboxlvl2AddItemDialog, item itemid was: " + to_string(itemid) + "");
										break;
									}
									if (itemid == 18 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
									{
										Player::OnTextOverlay(peer, "`4You can't place " + getItemDef(itemid).name + ".");
										break;
									}



									auto issafe = std::experimental::filesystem::exists("storageboxlvl2/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
									if (!issafe)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting Storage Box Xtreme - Level 2 info", 0, true);
										break;
									}

									int currentlyHave = 0;
									currentlyHave = GetQuantityOfItem(peer, itemid);

									auto contains = false;
									SearchInventoryItem(peer, itemid, currentlyHave, contains);
									if (!contains)
									{
										autoBan(peer, false, 24 * 7, "Used storage box lvl 2 exploit");
										break;
									}

									try
									{
										ifstream ifff("storageboxlvl2/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
										json j;
										ifff >> j;
										ifff.close();

										if (j["instorage"] > 19)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Storage Box Xtreme - Level 2 is full!", 0, true);
											break;
										}

										GTDialog mysafe;
										mysafe.addLabelWithIcon("`wStorage Box Xtreme - Level 2 info", 6288, LABEL_BIG);
										mysafe.addSmallText("You have " + to_string(currentlyHave) + " " + getItemDef(itemid).name + ". How many to store?");
										mysafe.addInputBox("boxlvl2depositcount_" + coord + "_" + to_string(itemid) + "", "", "", 5);
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addButton("boxlvl2depositconfirm", "Store items");
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addQuickExit();
										mysafe.endDialog("Close", "", "Exit");
										Player::OnDialogRequest(peer, mysafe.finishDialog());
									}
									catch (std::exception&)
									{
										SendConsole("boxlvl2deposit_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("boxlvl2deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("boxlvl2deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
								if (isboxlvl3AddItemDialog)
								{
									if (infoDat[0].substr(0, 15) == "boxlvl3deposit_") boxlvl3AddItemDialog = infoDat[1];
									if (boxlvl1AddItemDialog.size() > 5) break;
									string coord = infoDat[0].substr(15, infoDat[0].length() - 1).c_str();
									int itemid = atoi(boxlvl3AddItemDialog.c_str());


									if (itemid < 1 || itemid > maxItems)
									{
										autoBan(peer, false, 24 * 7, "Proxy detect! In isboxlvl3AddItemDialog, item itemid was: " + to_string(itemid) + "");
										break;
									}
									if (itemid == 18 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
									{
										Player::OnTextOverlay(peer, "`4You can't place " + getItemDef(itemid).name + ".");
										break;
									}

									auto issafe = std::experimental::filesystem::exists("storageboxlvl3/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
									if (!issafe)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting Storage Box Xtreme - Level 3 info", 0, true);
										break;
									}

									int currentlyHave = 0;
									currentlyHave = GetQuantityOfItem(peer, itemid);

									auto contains = false;
									SearchInventoryItem(peer, itemid, currentlyHave, contains);
									if (!contains)
									{
										autoBan(peer, false, 24 * 7, "Used storage box lvl 3 exploit");
										break;
									}

									try
									{
										ifstream ifff("storageboxlvl3/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
										json j;
										ifff >> j;
										ifff.close();

										if (j["instorage"] > 19)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Storage Box Xtreme - Level 3 is full!", 0, true);
											break;
										}

										GTDialog mysafe;
										mysafe.addLabelWithIcon("`wStorage Box Xtreme - Level 3 info", 6290, LABEL_BIG);
										mysafe.addSmallText("You have " + to_string(currentlyHave) + " " + getItemDef(itemid).name + ". How many to store?");
										mysafe.addInputBox("boxlvl3depositcount_" + coord + "_" + to_string(itemid) + "", "", "", 5);
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addButton("boxlvl3depositconfirm", "Store items");
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addQuickExit();
										mysafe.endDialog("Close", "", "Exit");
										Player::OnDialogRequest(peer, mysafe.finishDialog());
									}
									catch (std::exception&)
									{
										SendConsole("boxlvl3deposit_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("boxlvl3deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("boxlvl3deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
								if (isboxlvl1AddItemDialog)
								{
									if (infoDat[0].substr(0, 15) == "boxlvl1deposit_") boxlvl1AddItemDialog = infoDat[1];
									if (boxlvl1AddItemDialog.size() > 5) break;
									string coord = infoDat[0].substr(15, infoDat[0].length() - 1).c_str();
									int itemid = atoi(boxlvl1AddItemDialog.c_str());


									if (itemid < 1 || itemid > maxItems)
									{
										autoBan(peer, false, 24 * 7, "Proxy detect! In isaddItemToDonationBox, item itemid was: " + to_string(itemid) + "");
										break;
									}
									if (itemid == 18 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
									{
										Player::OnTextOverlay(peer, "`4You can't place " + getItemDef(itemid).name + ".");
										break;
									}

									auto issafe = std::experimental::filesystem::exists("storageboxlvl1/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
									if (!issafe)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting Storage Box Xtreme - Level 1 info", 0, true);
										break;
									}

									int currentlyHave = 0;
									currentlyHave = GetQuantityOfItem(peer, itemid);

									auto contains = false;
									SearchInventoryItem(peer, itemid, currentlyHave, contains);
									if (!contains)
									{
										autoBan(peer, false, 24 * 7, "Used storage box lvl 1 exploit");
										break;
									}

									try
									{
										ifstream ifff("storageboxlvl1/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
										json j;
										ifff >> j;
										ifff.close();

										if (j["instorage"] > 19)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Storage Box Xtreme - Level 1 is full!", 0, true);
											break;
										}

										GTDialog mysafe;
										mysafe.addLabelWithIcon("`wStorage Box Xtreme - Level 1 info", 6286, LABEL_BIG);
										mysafe.addSmallText("You have " + to_string(currentlyHave) + " " + getItemDef(itemid).name + ". How many to store?");
										mysafe.addInputBox("boxlvl1depositcount_" + coord + "_" + to_string(itemid) + "", "", "", 5);
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addButton("boxlvl1depositconfirm", "Store items");
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addQuickExit();
										mysafe.endDialog("Close", "", "Exit");
										Player::OnDialogRequest(peer, mysafe.finishDialog());
									}
									catch (std::exception&)
									{
										SendConsole("boxlvl1deposit_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("boxlvl1deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("boxlvl1deposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
								if (isMyTradeDialog)
								{
									if (infoDat[0].substr(0, 14) == "trademypicker_") {
										MyTradeItem = infoDat[1];
										if (SafeAddItemDialog.size() > 5) break;
										string number = infoDat[0].substr(14, infoDat[0].length() - 1).c_str();
										bool contains_non_int3 = !std::regex_match(number, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! isMyTradeDialog number was: " + number);
											break;
										}
										if (number.size() != 1)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! isMyTradeDialog number was: " + number);
											break;
										}
										if (number != "1" && number != "2" && number != "3" && number != "4")
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! isMyTradeDialog number was: " + number);
											break;
										}

										int itemid = atoi(MyTradeItem.c_str());
										if (itemid < 1 || itemid > maxItems)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! In isMyTradeDialog, item itemid was: " + to_string(itemid) + "");
											break;
										}
										if (itemid == 18 || itemid == 3308 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
										{
											Player::OnConsoleMessage(peer, "`4You can't place " + getItemDef(itemid).name + ".");
											TradeMainMenu(peer);
											break;
										}
										if (number == "1")
										{
											static_cast<PlayerInfo*>(peer->data)->mySellingItem1 = to_string(itemid);
										}
										if (number == "2")
										{
											static_cast<PlayerInfo*>(peer->data)->mySellingItem2 = to_string(itemid);
										}
										if (number == "3")
										{
											static_cast<PlayerInfo*>(peer->data)->mySellingItem3 = to_string(itemid);
										}
										if (number == "4")
										{
											static_cast<PlayerInfo*>(peer->data)->mySellingItem4 = to_string(itemid);
										}

										GTDialog picker;
										if (number == "1")
										{
											if (static_cast<PlayerInfo*>(peer->data)->mySellingItem1 == "3308")
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Choose item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
											else
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell and how much.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Change item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addSmallText("`$You have Selected: `2" + getItemDef(atoi(static_cast<PlayerInfo*>(peer->data)->mySellingItem1.c_str())).name);
												picker.addInputBox("trademypickercount_" + number, "Select how much you want to sell", "", 5);
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerconfirm", "Confirm");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
										}

										if (number == "2")
										{
											if (static_cast<PlayerInfo*>(peer->data)->mySellingItem2 == "3308")
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Choose item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
											else
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell and how much.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Change item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addSmallText("`$You have Selected: `2" + getItemDef(atoi(static_cast<PlayerInfo*>(peer->data)->mySellingItem2.c_str())).name);
												picker.addInputBox("trademypickercount_" + number, "Select how much you want to sell", "", 5);
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerconfirm", "Confirm");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
										}

										if (number == "3")
										{
											if (static_cast<PlayerInfo*>(peer->data)->mySellingItem3 == "3308")
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Choose item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
											else
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell and how much.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Change item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addSmallText("`$You have Selected: `2" + getItemDef(atoi(static_cast<PlayerInfo*>(peer->data)->mySellingItem3.c_str())).name);
												picker.addInputBox("trademypickercount_" + number, "Select how much you want to sell", "", 5);
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerconfirm", "Confirm");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
										}

										if (number == "4")
										{
											if (static_cast<PlayerInfo*>(peer->data)->mySellingItem4 == "3308")
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Choose item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
											else
											{
												picker.addLabelWithIcon("`wSelect which item you want to sell and how much.", 1434, LABEL_SMALL);
												picker.addSpacer(SPACER_SMALL);
												picker.addPicker("trademypicker_" + number, "Change item for sell", "Select your item");
												picker.addSpacer(SPACER_SMALL);
												picker.addSmallText("`$You have Selected: `2" + getItemDef(atoi(static_cast<PlayerInfo*>(peer->data)->mySellingItem4.c_str())).name);
												picker.addInputBox("trademypickercount_" + number, "Select how much you want to sell", "", 5);
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerconfirm", "Confirm");
												picker.addSpacer(SPACER_SMALL);
												picker.addButton("trademypickerback", "Back to main.");
												picker.addQuickExit();
												picker.endDialog("", "", "");
												Player::OnDialogRequest(peer, picker.finishDialog());
											}
										}
									}
								}
																if (isSafeAddItemDialog)
								{
									if (infoDat[0].substr(0, 12) == "safedeposit_") SafeAddItemDialog = infoDat[1];
									if (SafeAddItemDialog.size() > 5) break;
									string coord = infoDat[0].substr(12, infoDat[0].length() - 1).c_str();
									int itemid = atoi(SafeAddItemDialog.c_str());


									if (itemid < 1 || itemid > maxItems)
									{
										autoBan(peer, false, 24 * 7, "Proxy detect! In isSafeAddItemDialog, item itemid was: " + to_string(itemid) + "");
										break;
									}
									if (itemid == 18 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
									{
										Player::OnTextOverlay(peer, "`4You can't place " + getItemDef(itemid).name + ".");
										break;
									}

									auto issafe = std::experimental::filesystem::exists("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
									if (!issafe)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting donation box info.", 0, true);
										break;
									}

									int currentlyHave = 0;
									currentlyHave = GetQuantityOfItem(peer, itemid);

									auto contains = false;
									SearchInventoryItem(peer, itemid, currentlyHave, contains);
									if (!contains)
									{
										autoBan(peer, false, 24 * 7, "Used safe vault exploit");
										break;
									}

									try
									{
										ifstream ifff("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
										json j;
										ifff >> j;
										ifff.close();

										if (j["insafe"] > 19)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Safe Vault is full!", 0, true);
											break;
										}

										GTDialog mysafe;
										mysafe.addLabelWithIcon("`wSafe fault", 8878, LABEL_BIG);
										mysafe.addSmallText("You have " + to_string(currentlyHave) + " " + getItemDef(itemid).name + ". How many to store?");
										mysafe.addInputBox("safedepositcount_" + coord + "_" + to_string(itemid) + "", "", "", 5);
										mysafe.addSpacer(SPACER_SMALL);
										mysafe.addQuickExit();
										mysafe.endDialog("safedepositconfirm", "Store items", "Cancel");
										Player::OnDialogRequest(peer, mysafe.finishDialog());
									}
									catch (std::exception&)
									{
										SendConsole("safedeposit_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("safedeposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("safedeposit_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
								if (issafedepositconfirmDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) break;
									if (infoDat[0].substr(0, 17) == "safedepositcount_")
									{
										safedepositcount = infoDat[1];

										string coord_and_id = infoDat[0].erase(0, 17);
										string::size_type pos = coord_and_id.find('_');
										if (pos != std::string::npos)
										{
											safedepositcoord = coord_and_id.substr(0, pos);
											coord_and_id.erase(0, pos + 1);
											safedeposititemID = coord_and_id;
										}
										else
										{
											autoBan(peer, false, 24 * 7, "Incorrect parameters issafedepositconfirmDialog. Coord and id were: " + coord_and_id);
											break;
										}
										auto isdbox = std::experimental::filesystem::exists("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safedepositcoord + ".json");
										if (!isdbox)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting safe vault info.", 0, true);
											break;
										}

										bool contains_non_int3 = !std::regex_match(safedeposititemID, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! issafedepositconfirmDialog item id was: " + safedeposititemID);
											break;
										}

										bool contains_non_int4 = !std::regex_match(safedepositcount, std::regex("^[0-9]+$"));
										if (contains_non_int4 == true)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}
										givesafeitemCountInt = atoi(safedepositcount.c_str());

										givesafeitemItemIDInt = atoi(safedeposititemID.c_str());
										if (givesafeitemItemIDInt < 1 || givesafeitemItemIDInt > maxItems)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! In issafedepositconfirmDialog, givesafeitemItemIDInt was: " + to_string(givesafeitemItemIDInt) + "");
											break;
										}

										if (givesafeitemCountInt < 1 || givesafeitemCountInt > 200)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}

										try
										{
											ifstream ifff("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safedepositcoord + ".json");
											json j;
											ifff >> j;
											ifff.close();

											if (j["insafe"] > 19)
											{
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Safe fault is full!", 0, true);
												break;
											}
											bool isContains = false;
											SearchInventoryItem(peer, givesafeitemItemIDInt, givesafeitemCountInt, isContains);
											if (isContains == false)
											{
												Player::OnTextOverlay(peer, "`4You don't have enough " + itemDefs[givesafeitemItemIDInt].name + " in your inventory.");
												break;
											}
											j["insafe"] = j["insafe"].get<double>() + 1;

											for (int i = 0; i < 20; i++)
											{
												if (j["safe"][i]["itemid"] == 0)
												{
													j["safe"][i]["itemid"] = givesafeitemItemIDInt;
													j["safe"][i]["itemcount"] = givesafeitemCountInt;
													j["safe"][i]["placedby"] = static_cast<PlayerInfo*>(peer->data)->rawName;
													Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wStored " + to_string(givesafeitemCountInt) + " " + itemDefs[givesafeitemItemIDInt].name + " in the Safe Vault", 0, true);
													break;
												}
											}

											ofstream of("safevault/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + safedepositcoord + ".json");
											of << j << std::endl;
											of.close();
											RemoveInventoryItem(givesafeitemItemIDInt, givesafeitemCountInt, peer, true);
											updateplayerset(peer, givesafeitemItemIDInt);
										}
										catch (std::exception&)
										{
											SendConsole("safedepositcount_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("safedepositcount_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("safedepositcount_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}
																if (isgivedonationboxitemConfirm)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) break;
									if (infoDat[0].substr(0, 25) == "givedonationboxitemCount_")
									{
										givedonationboxitemCount = infoDat[1];
										string coord_and_id = infoDat[0].erase(0, 25);
										string::size_type pos = coord_and_id.find('_');
										if (pos != std::string::npos)
										{
											givedonationboxitemCoord = coord_and_id.substr(0, pos);
											coord_and_id.erase(0, pos + 1);
											givedonationboxitemItemID = coord_and_id;
										}
										else
										{
											autoBan(peer, false, 24 * 7, "Incorrect parameters isgivedonationboxitemConfirm. Coord and id were: " + coord_and_id);
											break;
										}
										auto isdbox = std::experimental::filesystem::exists("donationboxes/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + givedonationboxitemCoord + ".json");
										if (!isdbox)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting donation box info.", 0, true);
											break;
										}
										bool contains_non_int3 = !std::regex_match(givedonationboxitemItemID, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! isgivedonationboxitemConfirm id was: " + givedonationboxitemItemID);
											break;
										}
										bool contains_non_int4 = !std::regex_match(givedonationboxitemCount, std::regex("^[0-9]+$"));
										if (contains_non_int4 == true)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}
										givedonationboxitemCountInt = atoi(givedonationboxitemCount.c_str());
										givedonationboxitemItemIDInt = atoi(givedonationboxitemItemID.c_str());
										if (givedonationboxitemItemIDInt < 1 || givedonationboxitemItemIDInt > maxItems)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! In isgivedonationboxitemConfirm, givedonationboxitemCountInt was: " + to_string(givedonationboxitemItemIDInt) + "");
											break;
										}

										if (getItemDef(givedonationboxitemItemIDInt).rarity < 2)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4You can donate items higher than 2 rarity!", 0, true);
											break;
										}
										if (givedonationboxitemCountInt < 1 || givedonationboxitemCountInt > 200)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Count should be only 1-200", 0, true);
											break;
										}
									}
									if (infoDat[0] == "givedonationboxitemNote")
									{
										givedonationboxitemNote = infoDat[1];
										if (givedonationboxitemNote.size() < 1 || givedonationboxitemNote.size() > 50)
										{
											Player::OnTextOverlay(peer, "`4The note should be at least 1 letter.");
											break;
										}
										try
										{
											ifstream ifff("donationboxes/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + givedonationboxitemCoord + ".json");
											json j;
											ifff >> j;
											ifff.close();
											if (j["donated"] > 19)
											{
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Donation box is full!", 0, true);
												break;
											}
											bool isContains = false;
											SearchInventoryItem(peer, givedonationboxitemItemIDInt, givedonationboxitemCountInt, isContains);
											if (isContains == false)
											{
												autoBan(peer, false, 24 * 7, "Used donate box exploit");
												break;
											}
											j["donated"] = j["donated"].get<double>() + 1;
											for (int i = 0; i < 20; i++)
											{
												if (j["donatedItems"][i]["itemid"] == 0)
												{
													j["donatedItems"][i]["itemid"] = givedonationboxitemItemIDInt;
													j["donatedItems"][i]["itemcount"] = givedonationboxitemCountInt;
													j["donatedItems"][i]["sentBy"] = static_cast<PlayerInfo*>(peer->data)->displayName;
													j["donatedItems"][i]["note"] = givedonationboxitemNote;
													ENetPeer* currentPeer;
													for (currentPeer = server->peers;
														currentPeer < &server->peers[server->peerCount];
														++currentPeer)
													{
														if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
														if (isHere(peer, currentPeer))
														{
															Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`w[`5[`w" + static_cast<PlayerInfo*>(peer->data)->displayName + " `wplaces `5" + to_string(givedonationboxitemCountInt) + " `2" + getItemDef(givedonationboxitemItemIDInt).name + " `winto the Donation Box`5]`w]", 0, true);
															Player::OnConsoleMessage(currentPeer, "`w[`5[`w" + static_cast<PlayerInfo*>(peer->data)->displayName + " `wplaces `5" + to_string(givedonationboxitemCountInt) + " `2" + getItemDef(givedonationboxitemItemIDInt).name + " `winto the Donation Box`5]`w]");
															if (static_cast<PlayerInfo*>(peer->data)->lastPunchX >= 0 && static_cast<PlayerInfo*>(peer->data)->lastPunchY >= 0)
															{
																SendItemPacket(currentPeer, 1452, 0, static_cast<PlayerInfo*>(peer->data)->lastPunchX, static_cast<PlayerInfo*>(peer->data)->lastPunchY, 1);
															}
														}
													}
													break;
												}
											}
											ofstream of("donationboxes/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + givedonationboxitemCoord + ".json");
											of << j << std::endl;
											of.close();
											RemoveInventoryItem(givedonationboxitemItemIDInt, givedonationboxitemCountInt, peer, true);
											updateplayerset(peer, givedonationboxitemItemIDInt);
										}
										catch (std::exception&)
										{
											SendConsole("givedonationboxitemCount_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("givedonationboxitemCount_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("givedonationboxitemCount_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}

								if (isaddItemToDonationBox)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) break;
									if (infoDat[0].substr(0, 16) == "addDonationItem_") addItemToDonationBox = infoDat[1];
									if (addItemToDonationBox.size() > 5) break;
									string coord = infoDat[0].substr(16, infoDat[0].length() - 1).c_str();
									int itemid = atoi(addItemToDonationBox.c_str());


									if (itemid < 1 || itemid > maxItems)
									{
										autoBan(peer, false, 24 * 7, "Proxy detect! In isaddItemToDonationBox, item itemid was: " + to_string(itemid) + "");
										break;
									}
									if (itemid == 18 || itemid == 32 || itemid == 6336 || getItemDef(itemid).properties & Property_Untradable || getItemDef(itemid).blockType == BlockTypes::FISH || itemid == 8552 || itemid == 9472 || itemid == 9482 || itemid == 9356 || itemid == 9492 || itemid == 9498 || itemid == 8774 || itemid == 1790 || itemid == 2592 || itemid == 1784 || itemid == 1792 || itemid == 1794 || itemid == 7734 || itemid == 8306 || itemid == 9458)
									{
										Player::OnTextOverlay(peer, "`4You can't donate " + getItemDef(itemid).name + ".");
										break;
									}

									if (getItemDef(itemid).rarity < 2)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4You can donate items higher than 2 rarity!", 0, true);
										break;
									}

									auto isdbox = std::experimental::filesystem::exists("donationboxes/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
									if (!isdbox)
									{
										Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4An error occured while getting donation box info.", 0, true);
										break;
									}

									try
									{
										ifstream ifff("donationboxes/" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "/X" + coord + ".json");
										json j;
										ifff >> j;
										ifff.close();

										if (j["donated"] > 19)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Donation box is full!", 0, true);
											break;
										}

										GTDialog myDbox;
										myDbox.addLabelWithIcon(getItemDef(itemid).name, itemid, LABEL_BIG);
										myDbox.addSmallText("`$How many to put in the box as a gift? (Note: you will `4LOSE `$the items you give!)");
										myDbox.addInputBox("givedonationboxitemCount_" + coord + "_" + to_string(itemid) + "", "Count:", "", 5);
										myDbox.addSpacer(SPACER_SMALL);
										myDbox.addInputBox("givedonationboxitemNote", "Optional Note:", "", 50);

										myDbox.addSpacer(SPACER_SMALL);
										myDbox.addQuickExit();
										myDbox.endDialog("givedonationboxitemConfirm", "`4Give the item(s)", "Cancel");
										Player::OnDialogRequest(peer, myDbox.finishDialog());
									}
									catch (std::exception&)
									{
										SendConsole("addDonationItem_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("addDonationItem_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("addDonationItem_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
																if (isbuyPlayerStoreItemDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) continue;
									if (infoDat[0].substr(0, 23) == "buyPlayerStoreQuantity_")
									{
										buyPlayerStoreQuantity = infoDat[1];
										string pos_and_whoseStore = infoDat[0].erase(0, 23);
										string::size_type pos = pos_and_whoseStore.find('_');
										string apos = "";
										string whosStore = "";
										if (pos != std::string::npos)
										{
											apos = pos_and_whoseStore.substr(0, pos);
											pos_and_whoseStore.erase(0, pos + 1); // +1, kad "_" erase
											whosStore = pos_and_whoseStore;
										}
										else
										{
											autoBan(peer, false, 24 * 7, "Incorrect parameters in isbuyPlayerStoreItemDialog . Was:" + pos_and_whoseStore);
											break;
										}
										bool contains_non_int2 = !std::regex_match(apos, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											autoBan(peer, false, 24 * 7, "Incorrect aPos in isbuyPlayerStoreItemDialog .Was: " + apos);
											break;
										}
										bool existx = std::experimental::filesystem::exists("store/" + PlayerDB::getProperName(whosStore) + ".json");
										if (!existx)
										{
											Player::OnTextOverlay(peer, "`4Store does not exist");
											break;
										}
										buyPlayerStoreAposition = apos;
										buyPlayerStoreName = whosStore;
										if (buyPlayerStoreAposition.size() > 4 || buyPlayerStoreAposition.size() <= 0) break;
										int a_pos = stoi(buyPlayerStoreAposition);
										string name = buyPlayerStoreName;
										bool contains_non_int3 = !std::regex_match(buyPlayerStoreQuantity, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be 1-200");
											break;
										}
										if (buyPlayerStoreQuantity.size() > 3 || buyPlayerStoreQuantity.size() <= 0) break;
										int quantityBuy = stoi(buyPlayerStoreQuantity);
										if (quantityBuy < 1 || quantityBuy > 200)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be 1-200");
											break;
										}
										try
										{
											ifstream ifff("store/" + PlayerDB::getProperName(name) + ".json");
											json j;
											ifff >> j;
											ifff.close();
											bool found = false;
											bool error = false;
											bool error2 = false;
											for (int i = 0; i < j["itemsInStore"].size(); i++)
											{
												if (j["itemsInStore"][i]["aposition"] == a_pos)
												{
													found = true;
													if (j["itemsInStore"][i]["itemid"] == 0)
													{
														error = true;
														break;
													}
													if (j["itemsInStore"][i]["quantityOfItems"] == 0)
													{
														error2 = true;
														break;
													}
													int itemprice = j["itemsInStore"][i]["sellForItem"];
													int itempricePer = j["itemsInStore"][i]["sellPer"];
													int itemId = j["itemsInStore"][i]["itemid"];
													int quantity = j["itemsInStore"][i]["quantityOfItems"];
													if (quantityBuy > quantity)
													{
														Player::OnTextOverlay(peer, "`4There is no in shop " + to_string(quantityBuy) + " items.");
														break;
													}
													if (CheckItemExists(peer, j["itemsInStore"][i]["sellForItem"]) == false)
													{
														Player::OnConsoleMessage(peer, "`4You don't have " + itemDefs[j["itemsInStore"][i]["sellForItem"]].name + ".");
														break;
													}
													bool iscontains = false;
													SearchInventoryItem(peer, j["itemsInStore"][i]["sellForItem"], quantityBuy * itempricePer, iscontains);
													if (iscontains == false)
													{
														Player::OnConsoleMessage(peer, "`4You don't have enough(" + to_string(quantityBuy * itempricePer) + ") " + itemDefs[j["itemsInStore"][i]["sellForItem"]].name + ".");
														break;
													}
													bool success = false;
													if (CheckItemExists(peer, j["itemsInStore"][i]["itemid"]))
													{
														int currentlyHave = GetQuantityOfItem(peer, j["itemsInStore"][i]["itemid"]);
														if (quantityBuy + currentlyHave < 201)
														{
															SaveItemMoreTimes(j["itemsInStore"][i]["itemid"], quantityBuy, peer, success);
															j["itemsInStore"][i]["quantityOfItems"] = j["itemsInStore"][i]["quantityOfItems"].get<double>() - quantityBuy;
															Player::OnConsoleMessage(peer, "`2Successfully bought " + to_string(quantityBuy) + " " + itemDefs[j["itemsInStore"][i]["itemid"]].name + ".");
														}
														else
														{
															Player::OnConsoleMessage(peer, "`4You don't have enought space in your inventory to buy " + to_string(quantityBuy) + " " + itemDefs[j["itemsInStore"][i]["itemid"]].name + ".");
															break;
														}
													}
													else
													{
														if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == static_cast<PlayerInfo*>(peer->data)->currentInventorySize)
														{
															Player::OnTextOverlay(peer, "`4Your inventory is full! You can purchase an inventory upgrade in the shop.");
															break;
														}
														SaveItemMoreTimes(j["itemsInStore"][i]["itemid"], quantityBuy, peer, success);
														j["itemsInStore"][i]["quantityOfItems"] = j["itemsInStore"][i]["quantityOfItems"].get<double>() - quantityBuy;
														Player::OnConsoleMessage(peer, "`2Successfully bought " + to_string(quantityBuy) + " " + itemDefs[j["itemsInStore"][i]["itemid"]].name + ".");
													}
													RemoveInventoryItem(j["itemsInStore"][i]["sellForItem"], quantityBuy * itempricePer, peer, true);
													j["itemsInStore"][i]["boughtItems"] = j["itemsInStore"][i]["boughtItems"].get<double>() + (quantityBuy * itempricePer);
													vector<string> currentLogs;
													for (int i = 0; i < j["logs"].size(); i++)
													{
														currentLogs.push_back(j["logs"][i]);
													}
													time_t _tm = time(nullptr);
													struct tm* curtime = localtime(&_tm);
													string test = asctime(curtime);
													string tolog = test + " A new purchase from" + PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->rawName) + ": " + to_string(quantityBuy) + " " + itemDefs[j["itemsInStore"][i]["itemid"]].name + "";
													currentLogs.push_back(tolog);
													j["logs"] = currentLogs;
													j["newLogs"] = j["newLogs"].get<double>() + 1;
													std::ofstream oo("store/" + PlayerDB::getProperName(name) + ".json");
													if (!oo.is_open()) continue;
													oo << j << std::endl;
													ENetPeer* currentPeer;
													for (currentPeer = server->peers;
														currentPeer < &server->peers[server->peerCount];
														++currentPeer)
													{
														if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
															continue;
														if (PlayerDB::getProperName(name) == PlayerDB::getProperName(static_cast<PlayerInfo*>(currentPeer->data)->rawName))
														{
															Player::OnConsoleMessage(currentPeer, "`#You have received a new notification in your store! `$Check it out.");
															break;
														}
													}
													break;
												}
											}
											if (error)
											{
												Player::OnTextOverlay(peer, "`4Item does not exist in this store.");
												break;
											}
											if (error2)
											{
												Player::OnTextOverlay(peer, "`4Item sold out.");
												break;
											}
											if (!found)
											{
												Player::OnTextOverlay(peer, "`4Item does not exist in this store.");
												break;
											}
										}
										catch (std::exception&)
										{
											SendConsole("buyPlayerStoreQuantity_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("buyPlayerStoreQuantity_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("buyPlayerStoreQuantity_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}
								if (isstoreReviewConfirmDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) continue;
									if (infoDat[0].substr(0, 17) == "storeWriteReview_")
									{
										storeWriteReview = infoDat[1];
										storeWriteReviewShopName = infoDat[0].substr(infoDat[0].find("_") + 1);
										if (storeWriteReview.size() < 15)
										{
											Player::OnTextOverlay(peer, "`4Too short review.");
											break;
										}
										if (storeWriteReviewShopName.size() < 3)
										{
											Player::OnTextOverlay(peer, "`4System error. Try again.");
											break;
										}
									}

									if (infoDat[0] == "storeWriteReviewStar")
									{
										storeWriteReviewStar = infoDat[1];

										bool contains_non_int2 = !std::regex_match(storeWriteReviewStar, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											Player::OnTextOverlay(peer, "`4Stars should be 0-5");
											break;
										}
										if (storeWriteReviewStar.size() > 1 || storeWriteReviewStar.size() <= 0) break;
										int stars = stoi(storeWriteReviewStar);
										if (stars < 1 || stars > 5)
										{
											Player::OnTextOverlay(peer, "`4Stars should be 0-5");
											break;
										}
										bool existx = std::experimental::filesystem::exists("store/" + PlayerDB::getProperName(storeWriteReviewShopName) + ".json");
										if (!existx)
										{
											Player::OnTextOverlay(peer, "`4Store does not exist");
											continue;
										}
										try
										{
											ifstream ifff("store/" + PlayerDB::getProperName(storeWriteReviewShopName) + ".json");
											json j;
											ifff >> j;
											ifff.close();

											bool arRase = false;
											bool arRado = false;

											for (int i = 0; i < 50; i++)
											{
												if (j["storeReview"][i]["sentBy"].get<string>() == static_cast<PlayerInfo*>(peer->data)->displayName)
												{
													arRase = true;
													Player::OnTextOverlay(peer, "`4Unfortunately, but you have already sent the review in this store.");
													break;
												}
											}

											if (arRase == true)
											{
												break;
											}

											for (int i = 0; i < 50; i++)
											{
												if (j["storeReview"][i]["sentBy"].get<string>() == "")
												{
													j["storeReview"][i]["review"] = storeWriteReview;
													j["storeReview"][i]["sentBy"] = static_cast<PlayerInfo*>(peer->data)->displayName;
													j["storeReview"][i]["stars"] = stars;
													j["newLogs"] = j["newLogs"].get<double>() + 1;
													vector<string> currentLogs;
													for (int i = 0; i < j["logs"].size(); i++)
													{
														currentLogs.push_back(j["logs"][i]);
													}
													time_t _tm = time(nullptr);
													struct tm* curtime = localtime(&_tm);
													string test = asctime(curtime);

													string tolog = test + " You have received a new review from " + PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->rawName) + "(" + to_string(stars) + "/5): " + storeWriteReview + "";
													currentLogs.push_back(tolog);

													j["logs"] = currentLogs;


													std::ofstream oo("store/" + PlayerDB::getProperName(storeWriteReviewShopName) + ".json");
													if (!oo.is_open()) continue;
													oo << j << std::endl;

													Player::OnTextOverlay(peer, "`2Successfully sent.");
													arRado = true;


													ENetPeer* currentPeer;
													for (currentPeer = server->peers;
														currentPeer < &server->peers[server->peerCount];
														++currentPeer)
													{
														if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
															continue;
														if (PlayerDB::getProperName(storeWriteReviewShopName) == PlayerDB::getProperName(static_cast<PlayerInfo*>(currentPeer->data)->rawName))
														{
															Player::OnConsoleMessage(currentPeer, "`#You have received a new notification in your store! `$Check it out.");
															break;
														}
													}
													break;
												}
											}
											if (arRado == false)
											{
												Player::OnTextOverlay(peer, "`4Unfortunately, but the reviews in this store are overflowing.");
												break;
											}
										}
										catch (std::exception&)
										{
											SendConsole("storeWriteReview_ Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("storeWriteReview_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("storeWriteReview_ Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}
								if (isaddItemStoreOnSaleDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) continue;
									if (infoDat[0].substr(0, 21) == "storeItemPickerCount_")
									{
										storeItemPickerCount = infoDat[1];
										storeItemId = infoDat[0].substr(infoDat[0].find("_") + 1);
										if (storeItemPickerCount == "")
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										bool contains_non_int2 = !std::regex_match(storeItemPickerCount, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										if (storeItemPickerCount.size() > 3 || storeItemPickerCount.size() <= 0) break;
										int count = stoi(storeItemPickerCount);
										if (count < 1 || count > 200)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										bool contains_non_int3 = !std::regex_match(storeItemId, std::regex("^[0-9]+$"));
										if (contains_non_int3 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! In isaddItemStoreOnSaleDialog, item id was: " + storeItemId + "");
											break;
										}
										if (storeItemId.size() > 5 || storeItemId.size() <= 0) break;
										int id = stoi(storeItemId);
										if (id < 1 || id > maxItems)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! In isaddItemStoreOnSaleDialog, item id was: " + storeItemId + "");
											break;
										}
										if (id == 18 || id == 32 || id == 6336 || getItemDef(id).properties & Property_Untradable || getItemDef(id).blockType == BlockTypes::FISH || id == 8552 || id == 9472 || id == 9482 || id == 9356 || id == 9492 || id == 9498 || id == 8774 || id == 1790 || id == 2592 || id == 1784 || id == 1792 || id == 1794 || id == 7734 || id == 8306 || id == 9458)
										{
											Player::OnTextOverlay(peer, "`4You can't place on sale " + getItemDef(id).name + ".");
											break;
										}
										bool isContains = false;
										SearchInventoryItem(peer, id, count, isContains);
										if (isContains == false)
										{
											Player::OnTextOverlay(peer, "`4You don't have enough " + itemDefs[id].name + " in your inventory.");
											break;
										}
										bool existx = std::experimental::filesystem::exists("store/" + PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->rawName) + ".json");
										if (!existx)
										{
											Player::OnTextOverlay(peer, "`4You don't have your own store!");
											break;
										}
									}
									if (infoDat[0] == "storeItemDescription")
									{
										storeItemDescription = infoDat[1];
										if (storeItemDescription.size() <= 5)
										{
											Player::OnTextOverlay(peer, "`4Too short description.");
											break;
										}
									}
									if (infoDat[0] == "storeItemSellForItem")
									{
										storeItemSellForItem = infoDat[1];
										bool contains_non_int2 = !std::regex_match(storeItemSellForItem, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											Player::OnTextOverlay(peer, "`4Item Id should be more than 0 and lower than 201.");
											break;
										}
										if (storeItemSellForItem.size() > 5 || storeItemSellForItem.size() <= 0) break;
										int idd = stoi(storeItemSellForItem);
										if (idd < 1 || idd > maxItems)
										{
											Player::OnTextOverlay(peer, "`4Item Id should be more than 0 and lower than " + to_string(maxItems) + ".");
											break;
										}
										if (idd == 18 || idd == 32 || idd == 6336 || getItemDef(idd).properties & Property_Untradable || getItemDef(idd).blockType == BlockTypes::FISH || idd == 8552 || idd == 9472 || idd == 9482 || idd == 9356 || idd == 9492 || idd == 9498 || idd == 8774 || idd == 1790 || idd == 2592 || idd == 1784 || idd == 1792 || idd == 1794 || idd == 7734 || idd == 8306 || idd == 9458)
										{
											Player::OnTextOverlay(peer, "`4You can't choose " + getItemDef(idd).name + " as a price item.");
											break;
										}
									}
									if (infoDat[0] == "storeItemSellPer")
									{
										if (storeItemId.size() > 5 || storeItemId.size() <= 0) break;
										int id = stoi(storeItemId);
										if (storeItemPickerCount.size() > 3 || storeItemPickerCount.size() <= 0) break;
										int count = stoi(storeItemPickerCount);
										storeItemSellPer = infoDat[1];
										bool contains_non_int2 = !std::regex_match(storeItemSellPer, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										if (storeItemSellPer.size() > 5 || storeItemSellPer.size() <= 0) break;
										int sellPer = stoi(storeItemSellPer);
										if (sellPer < 1 || sellPer > 200)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										if (storeItemSellForItem.size() > 5 || storeItemSellForItem.size() <= 0) break;
										int sellForItem = stoi(storeItemSellForItem);
										try
										{
											ifstream ifff("store/" + PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->rawName) + ".json");
											json j;
											ifff >> j;
											ifff.close();
											int currentSpaceInStore = j["currentSpaceInStore"];
											bool arYraLaisvu = false;
											for (int i = 0; i < currentSpaceInStore; i++)
											{
												if (j["itemsInStore"][i]["itemid"] == 0)
												{
													j["itemsInStore"][i]["itemDesc"] = storeItemDescription;
													j["itemsInStore"][i]["itemid"] = id;
													j["itemsInStore"][i]["quantityOfItems"] = count;
													j["itemsInStore"][i]["sellForItem"] = sellForItem;
													j["itemsInStore"][i]["sellPer"] = sellPer;
													std::ofstream oo("store/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
													if (!oo.is_open()) continue;
													oo << j << std::endl;
													RemoveInventoryItem(id, count, peer, true);
													updateplayerset(peer, id);
													Player::OnTextOverlay(peer, "`2Successfully placed on sale!");
													arYraLaisvu = true;
													break;
												}
											}
											if (arYraLaisvu == false)
											{
												Player::OnTextOverlay(peer, "`4You don't have enough space in your store to put this item! Please buy an upgrade.");
												break;
											}
										}
										catch (std::exception&)
										{
											SendConsole("storeItemSellPer Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (std::runtime_error&)
										{
											SendConsole("storeItemSellPer Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
										catch (...)
										{
											SendConsole("storeItemSellPer Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
											if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
										}
									}
								}
								if (isBuyItemByRarityDialog)
								{
									if (world == nullptr || world->name == "EXIT" || serverIsFrozen) break;
									if (infoDat[0].substr(0, 18) == "buyitembyrarityid_")
									{
										strButItemByRarityCount = infoDat[1];
										string id = infoDat[0].substr(infoDat[0].find("_") + 1);

										if (strButItemByRarityCount == "")
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										if (strButItemByRarityCount.length() > 5)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										bool contains_non_int2 = !std::regex_match(strButItemByRarityCount, std::regex("^[0-9]+$"));
										if (contains_non_int2 == true)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}
										if (strButItemByRarityCount.size() > 3 || strButItemByRarityCount.size() <= 0)
										{
											break;
										}
										if (strButItemByRarityCount.size() > 3) break;
										int converted_count = stoi(strButItemByRarityCount);
										if (converted_count < 1 || converted_count > 200)
										{
											Player::OnTextOverlay(peer, "`4Quantity should be more than 0 and lower than 201.");
											break;
										}

										int realPrice = 0;
										if (id.size() > 5 || id.size() <= 0) break;
										if (realPrice <= 0)
										{
											realPrice = 1;
										}
										bool contains_non_int4 = !std::regex_match(id, std::regex("^[0-9]+$"));
										if (contains_non_int4 == true)
										{
											autoBan(peer, false, 24 * 7, "Proxy detect! when buying item by rarity from /buy. item id was: " + id);
											break;
										}
										int itemID = stoi(id);
										int itemid = stoi(id);
										if (getItemDef(itemID).name.find("Mooncake") != string::npos || getItemDef(itemID).name.find("Harvest") != string::npos && itemID != 1830 || getItemDef(itemID).name.find("Autumn") != string::npos || itemID == 1056 || itemID == 1804 || getItemDef(itemID).blockType == BlockTypes::COMPONENT || getItemDef(itemID).properties & Property_Chemical || itemID == 6920 || itemID == 6922 || itemID == 1874 || itemID == 1876 || itemID == 1904 || itemID == 1932 || itemID == 1900 || itemID == 1986 || itemID == 1996 || itemID == 2970 || itemID == 3140 || itemID == 3174 || itemID == 6028 || itemID == 6846 || itemID == 8962 || itemID == 2408 || itemID == 4428 || itemID == 5086 || itemID == 9240 || itemID == 9306 || itemID == 9290 || itemID == 7328 || itemID == 9416 || itemID == 10386 || itemID == 9410 || itemID == 1458 || itemID == 9408 || itemID == 9360 || itemID == 6866 || itemID == 6868 || itemID == 6870 || itemID == 6872 || itemID == 6874 || itemID == 6876 || itemID == 6878 || itemID == 2480 || itemID == 8452 || itemID == 5132 || itemID == 7166 || itemID == 5126 || itemID == 5128 || itemID == 5130 || itemID == 5144 || itemID == 5146 || itemID == 5148 || itemID == 5150 || itemID == 5162 || itemID == 5164 || itemID == 5166 || itemID == 5168 || itemID == 5180 || itemID == 5182 || itemID == 5184 || itemID == 5186 || itemID == 7168 || itemID == 7170 || itemID == 7172 || itemID == 7174 || itemID == 8834 || itemID == 7912 || itemID == 9212 || itemID == 5134 || itemID == 5152 || itemID == 5170 || itemID == 5188 || itemID == 980 || itemID == 9448 || itemID == 9310 || itemID == 10034 || itemID == 10036 || itemID == 8470 || itemID == 8286 || itemID == 6026 || itemID == 1970 || itemID == 1784 || itemID == 9356 || itemID == 10022 || itemID == 902 || itemID == 10032 || itemID == 834 || itemID == 6 || itemID == 5640 || itemID == 9492 || itemID == 1782 || itemID == 9288 || itemID == 1780 || itemID == 8306 || itemID == 202 || itemID == 204 || itemID == 206 || itemID == 2950 || itemID == 4802 || itemID == 4994 || itemID == 5260 || itemID == 5814 || itemID == 5980 || itemID == 7734 || itemID == 2592 || itemID == 2242 || itemID == 1794 || itemID == 1792 || itemID == 778 || itemID == 9510 || itemID == 8774 || itemID == 2568 || itemID == 9512 || itemID == 9502 || itemID == 9482 || itemID == 2250 || itemID == 2248 || itemID == 2244 || itemID == 2246 || itemID == 2286 || itemID == 9508 || itemID == 9504 || itemID == 9506 || itemID == 274 || itemID == 276 || itemID == 9476 || itemID == 1486 || itemID == 9498 || itemID == 4426 || itemID == 9496 || itemID == 278 || itemID == 9490 || itemID == 2410 || itemID == 9488 || itemID == 9452 || itemID == 9454 || itemID == 9472 || itemID == 9456 || itemID == 732 || itemID == 9458 || itemID == 6336 || itemID == 112 || itemID == 8 || itemID == 3760 || getItemDef(itemID).blockType == BlockTypes::FISH || itemID == 7372 || itemID == 9438 || itemID == 9462 || itemID == 9440 || itemID == 9442 || itemID == 9444 || itemID == 7960 || itemID == 7628 || itemID == 8552) break;
										if (itemid == 4296 || itemid == 6212 || itemid == 1212 || itemid == 1190 || itemid == 1206 || itemid == 1166 || itemid == 1964 || itemid == 1976 || itemid == 1998 || itemid == 1946 || itemid == 2002 || itemid == 1958 || itemid == 1952 || itemid == 2030 || itemid == 3104 || itemid == 3112 || itemid == 3120 || itemid == 3092 || itemid == 3094 || itemid == 3096 || itemid == 4184 || itemid == 4178 || itemid == 4174 || itemid == 4180 || itemid == 4170 || itemid == 4168 || itemid == 4150 || itemid == 1180 || itemid == 1224 || itemid == 5226 || itemid == 5228 || itemid == 5230 || itemid == 5212 || itemid == 5246 || itemid == 5242 || itemid == 5234 || itemid == 7134 || itemid == 7118 || itemid == 7132 || itemid == 7120 || itemid == 7098 || itemid == 9018 || itemid == 9038 || itemid == 9026 || itemid == 9066 || itemid == 9058 || itemid == 9044 || itemid == 9024 || itemid == 9032 || itemid == 9036 || itemid == 9028 || itemid == 9030 || itemid == 9110 || itemid == 9112 || itemid == 10386 || itemid == 10326 || itemid == 10324 || itemid == 10322 || itemid == 10328 || itemid == 10316 || itemid == 1198 || itemid == 1208 || itemid == 1222 || itemid == 1200 || itemid == 1220 || itemid == 1202 || itemid == 1238 || itemid == 1168 || itemid == 1172 || itemid == 1230 || itemid == 1194 || itemid == 1192 || itemid == 1226 || itemid == 1196 || itemid == 1236 || itemid == 1182 || itemid == 1184 || itemid == 1186 || itemid == 1188 || itemid == 1170 || itemid == 1212 || itemid == 1214 || itemid == 1232 || itemid == 1178 || itemid == 1234 || itemid == 1250 || itemid == 1956 || itemid == 1990 || itemid == 1968 || itemid == 1960 || itemid == 1948 || itemid == 1966 || itemid == 3114 || itemid == 3118 || itemid == 3100 || itemid == 3122 || itemid == 3124 || itemid == 3126 || itemid == 3108 || itemid == 3098 || itemid == 1962 || itemid == 2000 || itemid == 1970 || itemid == 4186 || itemid == 4188 || itemid == 4246 || itemid == 4248 || itemid == 4192 || itemid == 4156 || itemid == 4136 || itemid == 4152 || itemid == 4166 || itemid == 4190 || itemid == 4172 || itemid == 4182 || itemid == 4144 || itemid == 4146 || itemid == 4148 || itemid == 4140 || itemid == 4138 || itemid == 4142 || itemid == 5256 || itemid == 5208 || itemid == 5216 || itemid == 5218 || itemid == 5220 || itemid == 5214 || itemid == 5210 || itemid == 5254 || itemid == 5250 || itemid == 5252 || itemid == 5244 || itemid == 5236 || itemid == 7104 || itemid == 7124 || itemid == 7122 || itemid == 7102 || itemid == 7100 || itemid == 7126 || itemid == 7104 || itemid == 7124 || itemid == 7122 || itemid == 7102 || itemid == 7100 || itemid == 9048 || itemid == 9056 || itemid == 9114 || itemid == 9034 || itemid == 1210 || itemid == 1216 || itemid == 1218 || itemid == 1992 || itemid == 1982 || itemid == 1994 || itemid == 1972 || itemid == 1980 || itemid == 1988 || itemid == 1984 || itemid == 3116 || itemid == 3102 || itemid == 3106 || itemid == 3110 || itemid == 4160 || itemid == 4162 || itemid == 4164 || itemid == 4154 || itemid == 4158 || itemid == 5224 || itemid == 5222 || itemid == 5232 || itemid == 5240 || itemid == 5248 || itemid == 5238 || itemid == 5256 || itemid == 7116 || itemid == 7108 || itemid == 7110 || itemid == 7128 || itemid == 7112 || itemid == 7114 || itemid == 7130) break;
										if (itemid == 6398 || itemid == 6426 || itemid == 6340 || itemid == 6342 || itemid == 6350 || itemid == 6818 || itemid == 8244 || itemid == 8242 || itemid == 8240 || itemid == 8452 || itemid == 8454 || itemid == 8488 || itemid == 8498 || itemid == 8474 || itemid == 8476 || itemid == 8492 || itemid == 1498 || itemid == 1500 || itemid == 2804 || itemid == 2806 || itemid == 8270 || itemid == 8272 || itemid == 8274 || itemid == 3172 || itemid == 8478 || itemid == 8480 || itemid == 8486 || itemid == 8484 || itemid == 8482 || itemid == 8468 || itemid == 8494 || itemid == 8466 || itemid == 8490 || itemid == 8456 || itemid == 8458 || itemid == 8496 || itemid == 8472 || itemid == 5482 || itemid == 2240 || itemid == 3204 || itemid == 6114 || itemid == 4328 || itemid == 4326 || itemid == 4330 || itemid == 4324 || itemid == 4334 || itemid == 1242 || itemid == 1244 || itemid == 1246 || itemid == 1248 || itemid == 1282 || itemid == 1284 || itemid == 1286 || itemid == 1290 || itemid == 1288 || itemid == 1292 || itemid == 1294 || itemid == 1256 || itemid == 2586 || itemid == 782 || itemid == 3536 || itemid == 764 || itemid == 4176 || itemid == 4322 || itemid == 4080 || itemid == 2992 || itemid == 2976 || itemid == 3790 || itemid == 4990 || itemid == 1506 || itemid == 1274 || itemid == 9000 || itemid == 1252 || itemid == 8284 || itemid == 8954 || itemid == 8534 || itemid == 1460 || itemid == 1462 || itemid == 1466 || itemid == 1464 || itemid == 2386 || itemid == 2392 || itemid == 2394 || itemid == 4414 || itemid == 4420 || itemid == 4428 || itemid == 4426 || itemid == 5662 || itemid == 5642 || itemid == 5654 || itemid == 5646 || itemid == 5650 || itemid == 7828 || itemid == 7832 || itemid == 7834 || itemid == 9322 || itemid == 9344 || itemid == 9326 || itemid == 9316 || itemid == 9318 || itemid == 362 || itemid == 3398 || itemid == 386 || itemid == 4422 || itemid == 364 || itemid == 9340 || itemid == 9342 || itemid == 9332 || itemid == 9334 || itemid == 9336 || itemid == 9338 || itemid == 366 || itemid == 2388 || itemid == 7808 || itemid == 7810 || itemid == 4416 || itemid == 7818 || itemid == 7820 || itemid == 5652 || itemid == 7822 || itemid == 7824 || itemid == 5644 || itemid == 390 || itemid == 7826 || itemid == 7830 || itemid == 9324 || itemid == 5658 || itemid == 3396 || itemid == 2384 || itemid == 5660 || itemid == 3400 || itemid == 4418 || itemid == 4412 || itemid == 388 || itemid == 3408 || itemid == 1470 || itemid == 3404 || itemid == 3406 || itemid == 2390 || itemid == 5656 || itemid == 5648 || itemid == 2396 || itemid == 384 || itemid == 5664 || itemid == 4424 || itemid == 4400 || itemid == 362 || itemid == 3398 || itemid == 386 || itemid == 392 || itemid == 4422 || itemid == 364 || itemid == 9340 || itemid == 9342 || itemid == 9332 || itemid == 9334 || itemid == 9336 || itemid == 9338 || itemid == 366 || itemid == 2388 || itemid == 7808 || itemid == 7810 || itemid == 4416 || itemid == 7818 || itemid == 7820 || itemid == 5652 || itemid == 7822 || itemid == 7824 || itemid == 5644 || itemid == 390 || itemid == 7826 || itemid == 7830 || itemid == 9324 || itemid == 5658 || itemid == 3396 || itemid == 2384 || itemid == 5660 || itemid == 3400 || itemid == 4418 || itemid == 4412 || itemid == 388 || itemid == 3408 || itemid == 1470 || itemid == 3404 || itemid == 3406 || itemid == 2390 || itemid == 5656 || itemid == 5648 || itemid == 2396 || itemid == 384 || itemid == 5664 || itemid == 4424 || itemid == 4400 || itemid == 1458 || itemid == 362 || itemid == 3398 || itemid == 386 || itemid == 4422 || itemid == 364 || itemid == 9340 || itemid == 9342 || itemid == 9332 || itemid == 9334 || itemid == 9336 || itemid == 9338 || itemid == 366 || itemid == 2388 || itemid == 7808 || itemid == 7810 || itemid == 4416 || itemid == 7818 || itemid == 7820 || itemid == 5652 || itemid == 7822 || itemid == 7824 || itemid == 5644 || itemid == 390 || itemid == 7826 || itemid == 7830 || itemid == 9324 || itemid == 5658 || itemid == 3396 || itemid == 2384 || itemid == 5660 || itemid == 3400 || itemid == 4418 || itemid == 4412 || itemid == 388 || itemid == 3408 || itemid == 1470 || itemid == 3404 || itemid == 3406 || itemid == 2390 || itemid == 5656 || itemid == 5648 || itemid == 2396 || itemid == 384 || itemid == 5664 || itemid == 4424 || itemid == 4400 || itemid == 1458 || itemid == 5040 || itemid == 5042 || itemid == 5044 || itemid == 3402 || itemid == 5032 || itemid == 5034 || itemid == 5036 || itemid == 5038 || itemid == 5018 || itemid == 5022 || itemid == 5060 || itemid == 5054 || itemid == 5058 || itemid == 5056 || itemid == 5050 || itemid == 5046 || itemid == 5052 || itemid == 5048 || itemid == 5070 || itemid == 5072 || itemid == 5074 || itemid == 5076 || itemid == 5066 || itemid == 5062 || itemid == 5068 || itemid == 5064 || itemid == 5080 || itemid == 5082 || itemid == 5084 || itemid == 5078 || itemid == 10236 || itemid == 10232 || itemid == 10194 || itemid == 10206 || itemid == 10184 || itemid == 10192 || itemid == 10190 || itemid == 10186 || itemid == 10212 || itemid == 10214 || itemid == 10216 || itemid == 10220 || itemid == 10222 || itemid == 10224 || itemid == 10226 || itemid == 10208 || itemid == 10210 || itemid == 10218 || itemid == 10196 || itemid == 10198 || itemid == 10200 || itemid == 10202 || itemid == 10204) break;

										ItemDefinition itemDef = getItemDef(itemID);
										if (getItemDef(itemID).blockType == BlockTypes::FOREGROUND || getItemDef(itemID).blockType == BlockTypes::BACKGROUND || getItemDef(itemID).blockType == BlockTypes::GROUND_BLOCK)
										{
											if (getItemDef(itemID).rarity <= 10)
											{
												realPrice = round(static_cast<float>(1 * converted_count) / 10);
											}
											else if (getItemDef(itemID).rarity <= 20)
											{
												realPrice = round(static_cast<float>(5 * converted_count) / 10);
											}
											else if (getItemDef(itemID).rarity <= 40)
											{
												realPrice = round(static_cast<float>(15 * converted_count) / 10);
											}
											else if (getItemDef(itemID).rarity <= 60)
											{
												realPrice = round(static_cast<float>(20 * converted_count) / 10);
											}
											else if (getItemDef(itemID).rarity <= 80)
											{
												realPrice = round(static_cast<float>(25 * converted_count) / 10);
											}
											else if (getItemDef(itemID).rarity <= 100)
											{
												realPrice = round(static_cast<float>(30 * converted_count) / 10);
											}
											else
											{
												realPrice = round(static_cast<float>(35 * converted_count) / 10);
											}
										}
										else if (getItemDef(itemID).rarity == 999 && getItemDef(itemID).name.find("Golden") != string::npos)
										{
											realPrice = 9000 * converted_count;
										}
										else if (getItemDef(itemID).rarity == 999 && getItemDef(itemID).name.find("Phoenix") != string::npos)
										{
											realPrice = 5000 * converted_count;
										}
										else if (getItemDef(itemID).rarity == 999 && getItemDef(itemID).name.find("Nightmare") != string::npos)
										{
											realPrice = 4000 * converted_count;
										}
										else if (itemDef.properties & Property_Untradable)
										{
											realPrice = 3000 * converted_count;
										}
										else if (getItemDef(itemID).blockType == BlockTypes::CLOTHING)
										{
											ifstream infile("pricedata.txt");
											for (string line; getline(infile, line);)
											{
												if (line.length() > 3 && line[0] != '/' && line[1] != '/')
												{
													auto ex = explode("|", line);
													if (ex[0] == to_string(itemID))
													{
														realPrice = atoi(ex[1].c_str()) * converted_count;
														break;
													}
												}
											}
										}
										else if (itemID == 2912)
										{
											realPrice = 10 * converted_count;
										}
										else if (itemID == 1006)
										{
											realPrice = 15 * converted_count;
										}
										else if (itemID == 656)
										{
											realPrice = 15 * converted_count;
										}
										else if (itemID == 6286)
										{
											realPrice = 20 * converted_count;
										}
										else if (itemID == 6288)
										{
											realPrice = 50 * converted_count;
										}
										else if (itemID == 6290)
										{
											realPrice = 120 * converted_count;
										}
										else if (itemID == 3010)
										{
											realPrice = 120 * converted_count;
										}
										else if (itemID == 3040)
										{
											realPrice = 690 * converted_count;
										}
										else if (itemID == 3100)
										{
											realPrice = 3200 * converted_count;
										}
										else if (itemID == 5740)
										{
											realPrice = 9600 * converted_count;
										}
										else if (itemID == 2914)
										{
											realPrice = round(static_cast<float>(1 * converted_count) / 5);
										}
										else if (itemID == 3098)
										{
											realPrice = 5 * converted_count;
										}
										else if (itemID == 3218)
										{
											realPrice = 8 * converted_count;
										}
										else if (itemID == 3432)
										{
											realPrice = 90 * converted_count;
										}
										else if (itemID == 4246)
										{
											realPrice = 3 * converted_count;
										}
										else if (itemID == 4248)
										{
											realPrice = 3 * converted_count;
										}
										else if (itemID == 5528)
										{
											realPrice = 15 * converted_count;
										}
										else if (itemID == 1662)
										{
											realPrice = 30 * converted_count;
										}
										else if (itemID == 1452)
										{
											realPrice = 10 * converted_count;
										}
										else if (itemID == 8878)
										{
											realPrice = 80 * converted_count;
										}
										else if (itemID == 6918)
										{
											realPrice = 80 * converted_count;
										}
										else if (itemID == 6924)
										{
											realPrice = 60 * converted_count;
										}
										else if (itemID == 6840)
										{
											realPrice = 1200 * converted_count;
										}
										else if (itemID == 1436)
										{
											realPrice = 5 * converted_count;
										}
										else if (itemID == 2978)
										{
											realPrice = 5 * converted_count;
										}
										else if (itemID == 898)
										{
											realPrice = 60 * converted_count;
										}
										else if (itemID == 1966)
										{
											realPrice = 800 * converted_count;
										}
										else if (itemID == 5022)
										{
											realPrice = 350 * converted_count;
										}
										else if (itemID == 528)
										{
											realPrice = 25 * converted_count;
										}
										else if (itemID == 5638)
										{
											realPrice = 3500 * converted_count;
										}
										else if (itemID == 6946)
										{
											realPrice = 900 * converted_count;
										}
										else if (itemID == 6948)
										{
											realPrice = 300 * converted_count;
										}
										else if (itemID == 10012)
										{
											realPrice = 1800 * converted_count;
										}
										else if (itemID == 10016)
										{
											realPrice = 3500 * converted_count;
										}
										else if (itemID == 10018)
										{
											realPrice = 1200 * converted_count;
										}
										else if (getItemDef(itemID).clothType == ClothTypes::BACK && getItemDef(itemID).rarity == 999)
										{
											realPrice = 900 * converted_count;
										}
										else if (itemID == 10014)
										{
											realPrice = 1500 * converted_count;
										}
										else if (itemID == 2946)
										{
											realPrice = 5 * converted_count;
										}
										else if (itemID == 1404)
										{
											realPrice = 15 * converted_count;
										}
										else if (itemID == 874)
										{
											realPrice = 3 * converted_count;
										}
										else if (getItemDef(itemID).rarity == 999)
										{
											realPrice = 600 * converted_count;
										}
										else
										{
											realPrice = round(static_cast<float>(round(static_cast<float>(getItemDef(itemID).rarity) * 5) * converted_count) / 10);
										}
										if (realPrice <= 0)
										{
											realPrice = 1;
											//Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`1You can't buy below the minimum!", 0, true);
											//break;
										}
										if (CheckItemMaxed(peer, itemID, converted_count))
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`1(Item maxed)", 0, true);
											break;
										}
										if (CheckItemExists(peer, itemID) == false)
										{
											if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == static_cast<PlayerInfo*>(peer->data)->currentInventorySize)
											{
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`1(Inventory is full)", 0, true);
												break;
											}
										}

										if (itemID == 9644)
										{
											ifstream ifsz("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
											string content((std::istreambuf_iterator<char>(ifsz)), (std::istreambuf_iterator<char>()));
											int b = atoi(content.c_str());
											if (b > 25000 * converted_count)
											{
												bool success = true;
												SaveShopsItemMoreTimes(9644, converted_count, peer, success);
												if (!success)break;
												int gemcalc10k = b - 25000 * converted_count;
												ofstream myfile2;
												myfile2.open("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
												myfile2 << std::to_string(gemcalc10k);
												myfile2.close();
												ifstream ifszi("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
												string contentx((std::istreambuf_iterator<char>(ifszi)), (std::istreambuf_iterator<char>()));
												int updgem = atoi(contentx.c_str());
												Player::OnSetBux(peer, updgem, 0);
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`oYou have bought `$" + to_string(converted_count) + " " + getItemDef(itemID).name + " `ofor `$" + to_string(25000 * converted_count) + " Gems`o!", 0, true);
												ENetPeer* currentPeer;
												for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
												{
													if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
													if (isHere(peer, currentPeer))
													{
														SendTradeEffect(currentPeer, itemID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
														Player::PlayAudio(currentPeer, "audio/cash_register.wav", 0);
													}
												}
											}
											else Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "You can't afford that many!", 0, true);
											break;
										}
										if (itemID == 9644) break; /*svarbu!*/

										if (itemID == 2204)
										{
											ifstream ifsz("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
											string content((std::istreambuf_iterator<char>(ifsz)), (std::istreambuf_iterator<char>()));
											int b = atoi(content.c_str());
											if (b > 60000 * converted_count)
											{
												bool success = true;
												SaveShopsItemMoreTimes(2204, converted_count, peer, success);
												if (!success)break;
												int gemcalc10k = b - 60000 * converted_count;
												ofstream myfile2;
												myfile2.open("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
												myfile2 << std::to_string(gemcalc10k);
												myfile2.close();
												ifstream ifszi("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
												string contentx((std::istreambuf_iterator<char>(ifszi)), (std::istreambuf_iterator<char>()));
												int updgem = atoi(contentx.c_str());
												Player::OnSetBux(peer, updgem, 0);
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`oYou have bought `$" + to_string(converted_count) + " " + getItemDef(itemID).name + " `ofor `$" + to_string(60000 * converted_count) + " Gems`o!", 0, true);
												ENetPeer* currentPeer;
												for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
												{
													if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
													if (isHere(peer, currentPeer))
													{
														SendTradeEffect(currentPeer, itemID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
														Player::PlayAudio(currentPeer, "audio/cash_register.wav", 0);
													}
												}
											}
											else Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "You can't afford that many!", 0, true);
											break;
										}
										if (itemID == 2204) break; /*svarbu!*/

										if (CheckItemExists(peer, 242) == false && CheckItemExists(peer, 1796) == false)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`1You don't have wls and dls", 0, true);
											break;
										}

										auto worldlocks = 0;
										auto diamondlocks = 0;
										auto locks = 0;
										for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
										{
											if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 242)
											{
												worldlocks = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
											}
											if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1796)
											{
												diamondlocks = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
											}
										}
										if (diamondlocks > 0)
										{
											locks = diamondlocks * 100;
										}
										locks += worldlocks;
										if (realPrice > locks)
										{
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "You can't afford that many!", 0, true);
											break;
										}
										else
										{
											float worldlockskaina = 0;
											int diamondlockkiek = 0;
											int worldlockkiek = 0;
											if (realPrice > 0) worldlockkiek = realPrice;
											int grazinti_wl = 0;
											if (worldlockkiek != 0)
											{
												auto iscontainseas = false;
												SearchInventoryItem(peer, 242, worldlockkiek, iscontainseas);
												if (!iscontainseas)
												{
													//cout << "nera wl " + to_string(worldlockkiek) << endl;
													diamondlockkiek += 1;
													grazinti_wl = 100 - worldlockkiek;
													while (grazinti_wl < 0)
													{
														if (grazinti_wl < 0)
														{
															//cout << "grazinti_wl buvo " + to_string(grazinti_wl) << endl;
															diamondlockkiek += 1;
															grazinti_wl = 100 + grazinti_wl;
														}
														else break;
													}
													worldlockkiek = 0;
												}
											}
											if (diamondlockkiek != 0)
											{
												auto iscontainseas3 = false;
												SearchInventoryItem(peer, 1796, diamondlockkiek, iscontainseas3);
												if (!iscontainseas3)
												{
													//cout << "nera dl " + to_string(diamondlockkiek) << endl;
													diamondlockkiek -= 1;
													worldlockkiek += 100;
												}
											}
											if (worldlockkiek == 0 && diamondlockkiek == 0)
											{
												if (realPrice == worldlocks)
												{
													worldlockkiek = worldlocks;
												}
											}
											auto iscontainseas = false;
											SearchInventoryItem(peer, 242, worldlockkiek, iscontainseas);
											if (!iscontainseas)
											{
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "Uhm something went wrong...", 0, true);
												break;
											}
											if (worldlockkiek < 0 || diamondlockkiek < 0 || grazinti_wl < 0)
											{
												Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "Uhm something went wrong...", 0, true);
												break;
											}
											if (worldlockkiek == 0 && diamondlockkiek == 0) break;
											//cout << "duoda wl: " + to_string(worldlockkiek) << endl;
											//cout << "duoda dl: " + to_string(diamondlockkiek) << endl;
											//cout << "grazina wl: " + to_string(grazinti_wl) << endl;
											bool success = true;
											if (worldlockkiek != 0)
											{
												RemoveInventoryItem(242, worldlockkiek, peer, true);
											}
											if (diamondlockkiek != 0)
											{
												RemoveInventoryItem(1796, diamondlockkiek, peer, true);
											}
											if (grazinti_wl != 0)
											{
												if (CheckItemMaxed(peer, 242, grazinti_wl))
												{
													if (grazinti_wl >= 100 && !CheckItemMaxed(peer, 1796, 1))
													{
														SaveItemMoreTimes(1796, 1, peer, success);
													}
												}
												else
												{
													SaveItemMoreTimes(242, grazinti_wl, peer, success);
												}
											}
											SaveItemMoreTimes(itemID, converted_count, peer, success);
											Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`oYou have bought `$" + to_string(converted_count) + " " + getItemDef(itemID).name + " `ofor `$" + to_string(realPrice) + " World Locks`o!", 0, true);
											ENetPeer* currentPeer;
											for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
											{
												if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
												if (isHere(peer, currentPeer))
												{
													SendTradeEffect(currentPeer, itemID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
													Player::PlayAudio(currentPeer, "audio/cash_register.wav", 0);
												}
											}
										}

									}
								}