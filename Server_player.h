#pragma once
#include "stdafx.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <thread>
#include <time.h>
#include <vector>
#include <experimental/filesystem>
#include "json.hpp"
#include "Server_core.h"
#include "enet/enet.h"
using namespace std;
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using json = nlohmann::json;
int maxItems = 10388;
#define cloth0 cloth_hair
#define cloth1 cloth_shirt
#define cloth2 cloth_pants
#define cloth3 cloth_feet
#define cloth4 cloth_face
#define cloth5 cloth_hand
#define cloth6 cloth_back
#define cloth7 cloth_mask
#define cloth8 cloth_necklace
#define cloth9 cloth_ances
#define STRINT(x, y) (*(int*)(&(x)[(y)]))
#define STR16(x, y) (*(uint16_t*)(&(x)[(y)]))
vector<string> guildmem;
vector<string> guildelder;
vector<string> guildco;
#ifdef _WIN32
#include <windows.h>
typedef __int8 __int8_t;
typedef __int16 __int16_t;
#elif __APPLE__ || __linux__
typedef unsigned int DWORD;
#endif
typedef unsigned char BYTE;

struct InventoryItem
{
	__int16_t itemID;
	__int16_t itemCount;
};

struct PlayerInventory
{
	vector<InventoryItem> items;
};

struct PlayerInfo
{
	/*notvend*/
	string NickPrefix = "";
	/*Fishing*/
	bool Fishing = false;
	bool TriggerFish = false;
	int FishPosX = 0;
	int FishPosY = 0;
	string LastBait = "None";
	/*OnSuperMain*/
	string zf = "";
	/*ItemSuckers*/
	int magplantitemid = 0;
	int magplantx = 0;
	int magplanty = 0;
	string suckername = "";
	int suckerid = 0;
	/*PlayerLogin*/
	string email = "";
	bool HasLogged = false;
	bool isBot = true;
	/*Buffs*/
	bool GemBuffDrop = false;
	/*Consummables*/
	bool blueBerry = false;
	int usedBerry = 0;
	int lastBerry = 0;
	bool LuckyClover = false;
	int usedClover = 0;
	int lastClover = 0;
	bool SpikeJuice = false;
	int usedSpike = 0;
	int lastSpike = 0;
	bool PunchPotion = false;
	int usedPunchPotion = 0;
	int lastPunchPotion = 0;
	bool PlacePotion = false;
	int usedPlacePotion = 0;
	int lastPlacePotion = 0;
	/*PlayerName*/
	bool isDr = false;
	/*Misc*/
	bool passedname = false;
	bool passedheight = false;
	bool passedwidth = false;
	bool passedbackground = false;
	bool passedforeground = false;
	bool passedbedrock = false;
	string chatcolor = "";
	/**/
	bool isDisableMessages = false;
	/*HPSystem | PVP*/
	int lastPVPcoord = 0;
	int lastPVPcoord2 = 0;
	int lastPVPcoord3 = 0;
	int lastPVPcoord4 = 0;
	int lastPVPcoord5 = 0;
	long long int LastScanMSG;
	int lastPVPcoord6 = 0;
	int lastPVPcoord7 = 0;
	int health = 100;
	int score = 0;
	int noobCounter = 0;
	bool Growid = false;
	// end hp
	int wrenchedBlockLocation = -1;
	int displayfg = 0;
	int displaybg = 0;
	int displaypunchx = 0;
	int LastX = 0;
	bool UpdateFinisheds = true;
	int LastY = 0;
	int displaypunchy = 0;
	int lastsavemyworld = 0;
	int SubscribtionEndDay = 0;
	int lastdailyGems = 0;
	int packetinsec = 0;
	long long int packetsec = 0;
	int timeTogetToken = 0;
	int trashgemmeritem = 0;
	int eikiscia = 0;
	int bootybreaken = 0;
	bool UpdateFinished = true;
	string OriName = "";
	int wrenchx;
	int wrenchy;
	long long int lastSPIN = 0;
	int droppeditemcount = 0;
	int lastdroppeditemid = 0;
	int lastPunchX;
	bool blockLogin = false;
	int lastPunchY;
	int lastPunchForeground;
	int lastPunchBackground;
	bool isInWorld = false;
	bool GlobalChat = false;
	bool isBannedWait = false;
	bool usedCP = false;
	int TotalKills = 0;
	string skill = "None";
	string sid = "none";
	bool Console = false;
	bool isIn = false;
	string notebook = "";
	int netID;
	long long int startedTest = 0;
	string Chatname = "";
	bool Subscriber = false;
	int lastdropitemcount = 0;
	int lastdropitem = 0;
	int lasttrashitem = 0;
	int lasttrashitemcount = 0;
	long long int lastwarn = 0;
	int lastwarnCount = 0;
	int violations = 0;
	long long int lastcurse = 0;
	int lastcurseCount = 0;
	long long int lastban = 0;
	int lastbanCount = 0;
	long long int lastsuspend2w = 0;
	int lastsuspend2wCount = 0;
	long long int lastsuspend4w = 0;
	int lastsuspend4wCount = 0;
	long long int lastsuspend8w = 0;
	int lastsuspend8wCount = 0;
	long long int lastsuspendwrench = 0;
	int lastsuspendwrenchCount = 0;
	long long int lastbanipwrench = 0;
	int lastbanipwrenchCount = 0;
	long long int lastsuspend = 0;
	int lastsuspendCount = 0;
	int Awesomeness = 0;
	long long int lastdelete = 0;
	int lastdeleteCount = 0;
	long long int lastbanip = 0;
	int lastbanipCount = 0;
	long long int lastdelstatus = 0;
	int lastdelstatusCount = 0;
	int wrenchsession;
	bool ZiuriIKaire = false;
	int bitShiftTest = 0;
	bool canLeave = true;
	bool haveGrowId = false;
	bool haveGuestId = false;
	int valgem;
	int fEarth = 0;
	int fDark = 0;
	int plantgems = 0;
	int fFire = 0;
	int lavaLevel = 0;
	bool RotatedLeft = false;
	int fWater = 0;
	bool isRotatedLeft = false;
	string tankIDName = "";
	string tankIDPass = "";
	string requestedName = "";
	string rawName = "";
	int warns = 0;
	int bans = 0;
	int darkfragment = 0;
	int earthfragment = 0;
	int firefragment = 0;
	int waterfragment = 0;
	bool transsuccess = false;
	bool isModState = false;
	string displayName = "";
	bool wrongpass = false;
	int guildBg = 0;
	int guildFg = 0;
	string guildStatement = "";
	string guildLeader = "";
	string displayNamebackup = "";
	string displayUsername = "";
	vector<string> guildmatelist;
	vector<string> guildMembers;
	vector<string> worldsowned;
	vector<string> lastworlds;
	int guildlevel = 0;
	int guildexp = 0;
	bool isinvited = false;
	string createGuildName = "";
	string createGuildStatement = "";
	string createGuildFlagBg = "";
	string createGuildFlagFg = "";
	string guild = "";
	bool joinguild = false;
	string lastgm = "";
	string lastgmname = "";
	string lastgmworld = "";
	string guildlast = "";
	string msgName = "";
	bool isNicked = false;
	string country = "";
	string gameversion = "";
	string rid = "none";
	string gid = "none";
	string aid = "none";
	bool canExit = true;
	string vid = "none";
	string wkid = "";
	string metaip = "";
	string hash2 = "";
	string hash = "";
	string fhash = "";
	string mac = "none";
	string token = "";
	string user = "";
	string deviceversion = "";
	string doorID = "";
	string cbits = "";
	string lmode = "";
	string gdpr = "";
	string f = "";
	string fz = "";
	string hpid = "";
	string platformID = "";
	string player_age = "1";
	int adminLevel = 0;
	string currentWorld = "EXIT";
	bool radio = true;
	int x;
	int y;
	int x1;
	int y1;
	int posXY;
	int posX;
	int posY;
	int cpY;
	int cpX;
	int SignPosX;
	int SignPosY;
	bool characterLoaded = false;
	string charIP = "none";
	bool isDBanned = false;
	vector<string> friendinfo;
	vector<string> createfriendtable;
	vector<string> createworldsowned;
	string lastFrn = "";
	string lastFrnName = "";
	string lastFrnWorld = "";
	string lastMsger = "";
	string lastMsgerTrue = "";
	string lastMsgWorld = "";
	string lastSdbWorld = "";
	string lastSbbWorld = "";
	string lastfriend = "";
	string lastInfo = "";
	string lastInfoname = "";
	string lastDisplayname = "";
	string lastSeller = "";
	string lastSellWorld = "";
	string lastBuyer = "";
	string lastInfoAboutPlayer = "none";
	long int lastTradeAmount = 99999999999;
	string addgems = "1000 gems";
	int characterState = 0;
	int level = 1;
	int xp = 0;
	bool game1bet = false;
	bool game2bet = false;
	bool isUpdating = false;
	bool joinClothesUpdated = false;
	int effect = 8421376;
	int peffect = 8421376;
	bool taped = false;
	bool canCreate = false;
	int cloth_hair = 0; // 0
	int cloth_shirt = 0; // 1
	int cloth_pants = 0; // 2
	int cloth_feet = 0; // 3
	int cloth_face = 0; // 4
	int cloth_hand = 0; // 5
	int cloth_back = 0; // 6
	int cloth_mask = 0; // 7
	int cloth_necklace = 0; // 8
	int cloth_ances = 0; // 9
	int cur = 0;
	int ipID = 0;
	int ban = 0;
	bool canWalkInBlocks = false; // 1
	bool canDoubleJump = false; // 2
	bool cantsay = false;
	bool isInvisible = false; // 4
	bool noHands = false; // 8
	bool noEyes = false; // 16
	bool noBody = false; // 32	
	bool devilHorns = false; // 64
	bool goldenHalo = false; // 128
	bool isFrozen = false; // 2048
	bool isCursed = false; // 4096
	bool isDuctaped = false; // 8192
	unsigned long long int lastMuted = 0;
	unsigned long long int lastCursed = 0;
	bool haveCigar = false; // 16384
	bool isShining = false; // 32768
	bool isAncients = false; // 32768
	bool isAncients1 = false; // 32768
	bool isAncients2 = false; // 32768
	bool isAncients3 = false; // 32768
	bool isAncients4 = false; // 32768
	bool isAncients5 = false; // 32768
	bool isAncients6 = false; // 32768
	bool isZombie = false; // 65536
	bool isHitByLava = false; // 131072
	bool haveHauntedShadows = false; // 262144
	bool haveGeigerRadiation = false; // 524288
	bool haveReflector = false; // 1048576
	bool isEgged = false; // 2097152
	bool havePineappleFloag = false; // 4194304
	bool haveFlyingPineapple = false; // 8388608
	bool haveSuperSupporterName = false; // 16777216
	bool haveSupperPineapple = false; // 33554432
	bool isGhost = false;
	bool isinv = false;
	int skinColor = 0x8295C3FF;
	PlayerInventory inventory;
	/*surgery*/
	int Ultrasound = 0;
	bool PatientHeartStopped = false;
	long long int SurgeryTime = 0;
	bool SurgeryCooldown = false;
	float PatientTemperatureRise = 0;
	bool FixIt = false;
	bool UnlockedAntibiotic = false;
	bool PerformingSurgery = false;
	int SurgerySkill = 0;
	bool RequestedSurgery = false;
	string TempColor = "";
	bool HardToSee = false;
	bool PatientLosingBlood = false;
	int SurgItem1 = 4320;
	int SurgItem2 = 4320;
	int SurgItem3 = 4320;
	int SurgItem4 = 4320;
	int SurgItem5 = 4320;
	int SurgItem6 = 4320;
	int SurgItem7 = 4320;
	int SurgItem8 = 4320;
	int SurgItem9 = 4320;
	int SurgItem10 = 4320;
	int SurgItem11 = 4320;
	int SurgItem12 = 4320;
	int SurgItem13 = 4320;
	string PatientDiagnosis = "";
	string PatientPulse = "";
	string PatientStatus = "";
	float PatientTemperature = 0;
	string OperationSite = "";
	string IncisionsColor = "";
	int PatientIncisions = 0;
	string PatientRealDiagnosis = "";
	//trade stars
	long long int lastTrade = 0;
	string lastTradeGrowid = "";
	string MergeItem1 = "0";
	string MergeItem2 = "0";
	string MergeItem3 = "0";
	string mySellingItem1 = "3308";
	string mySellingItem2 = "3308";
	string mySellingItem3 = "3308";
	string mySellingItem4 = "3308";
	string mySellingItem1Count = "0";
	string mySellingItem2Count = "0";
	string mySellingItem3Count = "0";
	string mySellingItem4Count = "0";
	string hisSellingItem1 = "3308";
	string hisSellingItem2 = "3308";
	string hisSellingItem3 = "3308";
	string hisSellingItem4 = "3308";
	string hisSellingItem1Count = "0";
	string hisSellingItem2Count = "0";
	string hisSellingItem3Count = "0";
	string hisSellingItem4Count = "0";
	string receivedFrom = "";
	//trade ends
	short currentInventorySize = 0;
	long long int lastSB = 0;
	long long int lastSDB = 0;
	long long int lastSSB = 0;
	long long int lastINV = 0;
	long long int lastBREAK = 0;
	long long int lastMute = 0;
	long long int lastBan = 0;
	long long int lastCurse = 0;
	long long int lastATM = 0;
	long long int lastSYNC = 0;
	long long int lastDISPLAY = 0;
	int blockx;
	int blocky;
	bool isUseCode = false;
	bool isConfirmingCode = false;
	string registercode = "";
	string registermac = "";
	string registerrid = "";
	string registersid = "";
	string registergid = "";
	string registervid = "";
	string registeraid = "";
	string registerIP = "";
	int lastUserID = 0;
	int userID = 0;
	int respawnX = 0;
	int respawnY = 0;
	bool ischeck = false;
	int checkx = 0;
	int checky = 0;
	bool loadedInventory = false;
	long long int lastPunchTime = 0;
	long long int lastHitTime = 0;
	long long int lastJoinReq = 0;
	long long int lastsendclient = 0;
	long long int lastpacketflood = 0;
	long long int lastenterdoor = 0;
	uint32_t lavaHitAt = 0;
	uint32_t deadTime = 0;
};

struct PlayerMoving
{
	int packetType;
	int netID;
	float x;
	float y;
	int characterState;
	int plantingTree;
	float XSpeed;
	float YSpeed;
	int punchX;
	int punchY;
	int secondnetID;
};

struct Admin
{
	string username;
	string password;
	int level = 0;
	long long int lastSB = 0;
	long long int lastWarp = 0;
	long long int lastSpawn = 0;
	long long int lastasb = 0;
};

struct GamePacket
{
	BYTE* data;
	int len;
	int indexes;
};

enum ClothTypes
{
	HAIR,
	SHIRT,
	PANTS,
	FEET,
	FACE,
	HAND,
	BACK,
	MASK,
	NECKLACE,
	ANCES,
	NONE
};

inline int getState(PlayerInfo* info)
{
	auto val = 0;
	val |= info->canWalkInBlocks << 0;
	val |= info->canDoubleJump << 1;
	val |= info->cantsay << 13;
	val |= info->noHands << 3;
	val |= info->noEyes << 4;
	val |= info->noBody << 5;
	val |= info->goldenHalo << 7;
	val |= info->isFrozen << 8;
	val |= info->isCursed << 12;
	val |= info->isDuctaped << 13;
	val |= info->haveSuperSupporterName << 24;
	val |= info->isShining << 15;
	val |= info->isZombie << 16;
	val |= info->isHitByLava << 17;
	return val;
}

class Player
{
public:
	static void OnConsoleMessage(ENetPeer* peer, string text);
	static void OnTalkBubble(ENetPeer* peer, int netID, string text, int chatColor, bool isOverlay);
	static void OnAddNotification(ENetPeer* peer, string text, string audiosound, string interfaceimage);
	static void OnRemove(ENetPeer* peer, int netID);
	static void OnSendToServer(ENetPeer* peer, int userID, int token, string ip, int port, string doorId, int lmode); // no need other args, sub servers done&working already... using fake data etc.
	static void PlayAudio(ENetPeer* peer, string audioFile, int delayMS);
	static void OnZoomCamera(ENetPeer* peer, float value1, int value2);
	static void SmoothZoom(ENetPeer* peer);
	static void OnRaceStart(ENetPeer* peer, int netID);
	static void OnRaceEnd(ENetPeer* peer, int netID);
	static void OnSetCurrentWeather(ENetPeer* peer, int weather);
	static void OnPlayPositioned(ENetPeer* peer, string audiofile, int netID, bool broadcastInWorld, ENetPacket* pk);
	static void OnCountdownStart(ENetPeer* peer, int netID, int time, int score);
	static void OnStartTrade(ENetPeer* peer, string displayName, int netID);
	static void OnTextOverlay(ENetPeer* peer, string text);
	static void OnForceTradeEnd(ENetPeer* peer);
	static void OnFailedToEnterWorld(ENetPeer* peer);
	static void OnNameChanged(ENetPeer* peer, int netID, string name);
	static void OnDialogRequest(ENetPeer* peer, string args);
	static void OnKilled(ENetPeer* peer, int netID);
	static void OnSetFreezeState(ENetPeer* peer, int state, int netID);
	static void OnSetPos(ENetPeer* peer, int netID, int x, int y);
	static void OnInvis(ENetPeer* peer, int state, int netID);
	static void OnChangeSkin(ENetPeer* peer, int skinColor, int netID);
	static void SetRespawnPos(ENetPeer* peer, int posX, int posY, int netID);
	static void OnSetBux(ENetPeer* peer, int gems, int accountstate);
	static void OnParticleEffect(ENetPeer* peer, int effect, float x, float y, int delay);
	static void SetHasGrowID(ENetPeer* peer, int status, string username, string password);
	static void Ping(ENetPeer* peer);
};

class PlayerDB
{
public:
	static string getProperName(string name);
	static string fixColors(string text);
	static int playerLogin(ENetPeer* peer, string username, string password);
	static int playerRegister(ENetPeer* peer, string username, string password, string email);
	static int guildRegister(ENetPeer* peer, string guildName, string guildStatement, string guildFlagfg, string guildFlagbg);
};

inline string PlayerDB::getProperName(string name)
{
	string newS;
	for (auto c : name) newS += (c >= 'A' && c <= 'Z') ? c - ('A' - 'a') : c;
	string ret;
	for (auto i = 0; i < newS.length(); i++)
	{
		if (newS[i] == '`') i++;
		else ret += newS[i];
	}
	string ret2;
	for (auto c : ret) if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) ret2 += c;
	return ret2;
}

inline string PlayerDB::fixColors(string text)
{
	string ret = "";
	auto colorLevel = 0;
	for (auto i = 0; i < text.length(); i++)
	{
		if (text[i] == '`')
		{
			ret += text[i];
			if (i + 1 < text.length())
				ret += text[i + 1];
			if (i + 1 < text.length() && text[i + 1] == '`')
			{
				colorLevel--;
			}
			else
			{
				colorLevel++;
			}
			i++;
		}
		else
		{
			ret += text[i];
		}
	}
	for (auto i = 0; i < colorLevel; i++)
	{
		ret += "``";
	}
	for (auto i = 0; i > colorLevel; i--)
	{
		ret += "`w";
	}
	return ret;
}

inline GamePacket appendFloat(GamePacket p, float val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 1;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendFloat(GamePacket p, float val, float val2)
{
	const auto n = new BYTE[p.len + 2 + 8];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 3;
	memcpy(n + p.len + 2, &val, 4);
	memcpy(n + p.len + 6, &val2, 4);
	p.len = p.len + 2 + 8;
	p.indexes++;
	return p;
}

inline GamePacket appendFloat(GamePacket p, float val, float val2, float val3)
{
	const auto n = new BYTE[p.len + 2 + 12];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 4;
	memcpy(n + p.len + 2, &val, 4);
	memcpy(n + p.len + 6, &val2, 4);
	memcpy(n + p.len + 10, &val3, 4);
	p.len = p.len + 2 + 12;
	p.indexes++;
	return p;
}

inline GamePacket appendInt(GamePacket p, int val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 9;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendIntx(GamePacket p, int val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 5;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendString(GamePacket p, string str)
{
	const auto n = new BYTE[p.len + 2 + str.length() + 4];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 2;
	int sLen = str.length();
	memcpy(n + p.len + 2, &sLen, 4);
	memcpy(n + p.len + 6, str.c_str(), sLen);
	p.len = p.len + 2 + str.length() + 4;
	p.indexes++;
	return p;
}

inline GamePacket createPacket()
{
	const auto data = new BYTE[61];
	string asdf = "0400000001000000FFFFFFFF00000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	for (auto i = 0; i < asdf.length(); i += 2)
	{
		char x = ch2n(asdf[i]);
		x = x << 4;
		x += ch2n(asdf[i + 1]);
		memcpy(data + (i / 2), &x, 1);
		if (asdf.length() > 61 * 2) throw 0;
	}
	GamePacket packet;
	packet.data = data;
	packet.len = 61;
	packet.indexes = 0;
	return packet;
}

inline GamePacket packetEnd(GamePacket p)
{
	const auto n = new BYTE[p.len + 1];
	memcpy(n, p.data, p.len);
	delete p.data;
	p.data = n;
	char zero = 0;
	memcpy(p.data + p.len, &zero, 1);
	p.len += 1;
	*reinterpret_cast<int*>(p.data + 56) = p.indexes;
	*static_cast<BYTE*>(p.data + 60) = p.indexes;
	return p;
}

inline BYTE* packPlayerMoving(PlayerMoving* dataStruct)
{
	const auto data = new BYTE[64];
	for (auto i = 0; i < 64; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 4, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 20, &dataStruct->plantingTree, 4);
	memcpy(data + 24, &dataStruct->x, 4);
	memcpy(data + 28, &dataStruct->y, 4);
	memcpy(data + 32, &dataStruct->XSpeed, 4);
	memcpy(data + 36, &dataStruct->YSpeed, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	return data;
}

string packPlayerMoving2(PlayerMoving* dataStruct)
{
	string data;
	data.resize(56);
	STRINT(data, 0) = dataStruct->packetType;
	STRINT(data, 4) = dataStruct->netID;
	STRINT(data, 12) = dataStruct->characterState;
	STRINT(data, 20) = dataStruct->plantingTree;
	STRINT(data, 24) = *(int*)&dataStruct->x;
	STRINT(data, 28) = *(int*)&dataStruct->y;
	STRINT(data, 32) = *(int*)&dataStruct->XSpeed;
	STRINT(data, 36) = *(int*)&dataStruct->YSpeed;
	STRINT(data, 44) = dataStruct->punchX;
	STRINT(data, 48) = dataStruct->punchY;
	return data;
}

inline PlayerMoving* unpackPlayerMoving(BYTE* data)
{
	auto dataStruct = new PlayerMoving;
	memcpy(&dataStruct->packetType, data, 4);
	memcpy(&dataStruct->netID, data + 4, 4);
	memcpy(&dataStruct->characterState, data + 12, 4);
	memcpy(&dataStruct->plantingTree, data + 20, 4);
	memcpy(&dataStruct->x, data + 24, 4);
	memcpy(&dataStruct->y, data + 28, 4);
	memcpy(&dataStruct->XSpeed, data + 32, 4);
	memcpy(&dataStruct->YSpeed, data + 36, 4);
	memcpy(&dataStruct->punchX, data + 44, 4);
	memcpy(&dataStruct->punchY, data + 48, 4);
	return dataStruct;
}

inline long long GetCurrentTimeInternal()
{
	using namespace std::chrono;
	return (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
}

inline long long GetCurrentTimeInternalSeconds()
{
	using namespace std::chrono;
	return (duration_cast<seconds>(system_clock::now().time_since_epoch())).count();
}

inline int calcBanDuration(const long long banDuration)
{
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	auto duration = 0;
	duration = banDuration - GetCurrentTimeInternalSeconds();
	if (duration <= 0) return 0;
	else return duration;
}

inline string OutputBanTime(int n)
{
	string x;
	const auto day = n / (24 * 3600);
	if (day != 0) x.append(to_string(day) + " Days ");
	n = n % (24 * 3600);
	const auto hour = n / 3600;
	if (hour != 0) x.append(to_string(hour) + " Hours ");
	n %= 3600;
	const auto minutes = n / 60;
	if (minutes != 0) x.append(to_string(minutes) + " Minutes ");
	n %= 60;
	const auto seconds = n;
	if (seconds != 0) x.append(to_string(seconds) + " Seconds");
	return x;
}

inline void banLoginDevice(ENetPeer* peer, const long long banDurationDefault, string sid, string mac)
{
	const auto bantimeleft = calcBanDuration(banDurationDefault);
	if (bantimeleft < 1) return;
	const auto text = "action|log\nmsg|`4Sorry, this device or location is still banned for `w" + OutputBanTime(calcBanDuration(banDurationDefault)) + " Need help? Contact Sebia#0001!";
	const string dc = "https://discord.gg/VSkajzV";
	const auto url = "action|set_url\nurl|" + dc + "\nlabel|Join GTOS Discord\n";
	const auto data = new BYTE[5 + text.length()];
	const auto dataurl = new BYTE[5 + url.length()];
	BYTE zero = 0;
	auto type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	memcpy(dataurl, &type, 4);
	memcpy(dataurl + 4, url.c_str(), url.length());
	memcpy(dataurl + 4 + url.length(), &zero, 1);
	const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p);
	const auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p3);
	delete data;
	delete dataurl;
	static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
}

inline void SendInventory(ENetPeer* peer, PlayerInventory inventory)
{
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	const int inventoryLen = inventory.items.size();
	const auto packetLen = 66 + (inventoryLen * 4) + 4;
	auto* data2 = new BYTE[packetLen];
	auto MessageType = 0x4;
	auto PacketType = 0x9;
	auto NetID = -1;
	auto CharState = 0x8;
	memset(data2, 0, packetLen);
	memcpy(data2, &MessageType, 4);
	memcpy(data2 + 4, &PacketType, 4);
	memcpy(data2 + 8, &NetID, 4);
	memcpy(data2 + 16, &CharState, 4);
	//int endianInvVal = __builtin_bswap32(inventoryLen);
	int endianInvVal = _byteswap_ulong(inventoryLen);
	memcpy(data2 + 66 - 4, &endianInvVal, 4);
	//endianInvVal = __builtin_bswap32(static_cast<PlayerInfo*>(peer->data)->currentInventorySize);
	endianInvVal = _byteswap_ulong(static_cast<PlayerInfo*>(peer->data)->currentInventorySize);
	memcpy(data2 + 66 - 8, &endianInvVal, 4);
	auto val = 0;
	for (auto i = 0; i < inventoryLen; i++)
	{
		val = 0;
		val |= inventory.items.at(i).itemID;
		val |= inventory.items.at(i).itemCount << 16;
		val &= 0x00FFFFFF;
		val |= 0x00 << 24;
		memcpy(data2 + (i * 4) + 66, &val, 4);
	}
	const auto packet3 = enet_packet_create(data2, packetLen, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet3);
	delete data2;
}

inline bool CheckItemExists(ENetPeer* peer, const int fItemId)
{
	auto isExists = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId)
		{
			isExists = true;
			break;
		}
	}
	return isExists;
}

inline void SearchInventoryItem(ENetPeer* peer, const int fItemid, const int fQuantity, bool& iscontains)
{
	iscontains = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= fQuantity)
		{
			iscontains = true;
			break;
		}
	}
}

inline bool SearchInventoryItemsForGame2(ENetPeer* peer)
{
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 9484 || static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 9486 || static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 9494 || static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 9502)
		{
			return true;
		}
	}
	return false;
}

inline bool isHere(ENetPeer* peer, ENetPeer* peer2)
{
	return static_cast<PlayerInfo*>(peer->data)->currentWorld == static_cast<PlayerInfo*>(peer2->data)->currentWorld;
}

inline void SendPacketRaw(int a1, void* packetData, const size_t packetDataSize, void* a4, ENetPeer* peer, const int packetFlag)
{
	ENetPacket* p;
	if (peer)
	{
		if (a1 == 4 && *(static_cast<BYTE*>(packetData) + 12) & 8)
		{
			p = enet_packet_create(nullptr, packetDataSize + *(static_cast<DWORD*>(packetData) + 13) + 5, packetFlag);
			auto four = 4;
			memcpy(p->data, &four, 4);
			memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
			memcpy(reinterpret_cast<char*>(p->data) + packetDataSize + 4, a4, *(static_cast<DWORD*>(packetData) + 13));
			enet_peer_send(peer, 0, p);
		}
		else
		{
			try
			{
				p = enet_packet_create(nullptr, packetDataSize + 5, packetFlag);
				memcpy(p->data, &a1, 4);
				memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
				enet_peer_send(peer, 0, p);
			}
			catch (...)
			{
				SendConsole("Failed to send packet raw (sendpacketraw)", "ERROR");
			}
		}
	}
	delete static_cast<char*>(packetData);
}

inline void playerconfig(ENetPeer* peer, const int yspeed, const int xspeed, const int packettype)
{
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer))
		{
			PlayerMoving data;
			auto water = 125.0f;
			data.packetType = packettype;
			data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
			data.x = 1000;
			if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 366)
			{
				data.y = -400;
			}
			else
			{
				data.y = 400;
			}
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = xspeed;
			data.YSpeed = yspeed;
			data.netID = netID;
			data.plantingTree = state;
			const auto raw = packPlayerMoving(&data);
			auto var = 0x818100;
			memcpy(raw + 1, &var, 3);
			memcpy(raw + 16, &water, 4);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}

inline void sendPuncheffectpeer(ENetPeer* peer, const int punch)
{
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	PlayerMoving data;
	auto water = 125.0f;
	data.packetType = 0x14;
	data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
	data.x = 1000;
	if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 366)
	{
		data.y = -400;
	}
	else
	{
		data.y = 400;
	}
	data.punchX = -1;
	data.punchY = -1;
	data.XSpeed = 300;
	if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9472)
	{
		data.YSpeed = 600;
	}
	else
	{
		data.YSpeed = 1000;
	}
	data.netID = netID;
	data.plantingTree = state;
	const auto raw = packPlayerMoving(&data);
	auto var = punch;
	memcpy(raw + 1, &var, 3);
	memcpy(raw + 16, &water, 4);
	SendPacketRaw(4, raw, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	if (static_cast<PlayerInfo*>(peer->data)->isZombie == true)
	{
		playerconfig(peer, 1150, 130, 0x14);
	}
}

inline void sendPuncheffect(ENetPeer* peer, int punch)
{
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (ENetPeer* currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer))
		{
			if (peer != currentPeer)
			{
				PlayerMoving data;
				data.packetType = 0x14;
				data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
				data.x = 1000;
				data.y = 100;
				data.x = 1000;
				data.y = 1000;
				data.punchX = 0;
				data.punchY = 0;
				data.XSpeed = 300;
				data.YSpeed = 600;
				data.netID = netID;
				data.plantingTree = state;
				const auto raw = packPlayerMoving(&data);
				auto var = punch;
				memcpy(raw + 1, &var, 3);
				SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
			}
			if (static_cast<PlayerInfo*>(peer->data)->haveGrowId && static_cast<PlayerInfo*>(peer->data)->isIn == true && static_cast<PlayerInfo*>(peer->data)->currentWorld != "EXIT")
			{
				ofstream WorldSys("misc/effect/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				WorldSys << to_string(static_cast<PlayerInfo*>(peer->data)->effect);
				WorldSys.close();
			}
		}
	}
	if (static_cast<PlayerInfo*>(peer->data)->isZombie == true)
	{
		playerconfig(peer, 1150, 130, 0x14);
	}
}

inline void sendClothes(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
	for (ENetPeer* currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer))
		{
			memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet3);
		}
	}
	delete p3.data;
}

inline void updateplayerset(ENetPeer* peer, int targetitem)
{
	const auto clothitem = static_cast<PlayerInfo*>(peer->data)->cloth_hand;
	const auto clothface = static_cast<PlayerInfo*>(peer->data)->cloth_face;
	const auto clothneck = static_cast<PlayerInfo*>(peer->data)->cloth_necklace;
	const auto clothshirt = static_cast<PlayerInfo*>(peer->data)->cloth_shirt;
	const auto clothback = static_cast<PlayerInfo*>(peer->data)->cloth_back;
	const auto clothances = static_cast<PlayerInfo*>(peer->data)->cloth_ances;
	const auto clothpants = static_cast<PlayerInfo*>(peer->data)->cloth_pants;
	const auto clothfeet = static_cast<PlayerInfo*>(peer->data)->cloth_feet;
	const auto clothhair = static_cast<PlayerInfo*>(peer->data)->cloth_hair;
	const auto clothmask = static_cast<PlayerInfo*>(peer->data)->cloth_mask;
	const auto item = targetitem;
	if (clothmask == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_mask = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}
	if (clothitem == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_hand = 0;
			sendClothes(peer);
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
			sendPuncheffectpeer(peer, static_cast<PlayerInfo*>(peer->data)->effect);
			sendPuncheffect(peer, static_cast<PlayerInfo*>(peer->data)->effect);
		}
		else
		{
		}
	}
	if (clothface == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_face = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothneck == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_necklace = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothshirt == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_shirt = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothback == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_back = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothances == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_ances = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothpants == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_pants = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothfeet == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_feet = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}

	if (clothhair == item)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_hair = 0;
			sendClothes(peer);
		}
		else
		{
		}
	}
}

inline void InventoryUpdater()
{
	/*conn3 = mysql_init(nullptr);
	unsigned int mysql_ct;
	mysql_ct = 28800;
	mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
	conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
	if (conn3 != nullptr)
	{
		SendConsole("Connection to mysql successfully! (UpdateInventoryThread)", "MYSQL");
		Connected = true;
	}
	else
	{
		SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
		Connected = false;
	}
	MYSQL_ROW row;
	while (InventoryUpdater)
	{
		Sleep(1500);
		for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
			if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == "EXIT") continue;
			if (!static_cast<PlayerInfo*>(currentPeer->data)->isIn) continue;
			if (!static_cast<PlayerInfo*>(currentPeer->data)->haveGrowId) continue;
			string username = static_cast<PlayerInfo*>(currentPeer->data)->rawName;
			auto inventoryExists = std::experimental::filesystem::exists("inventory/" + username + ".json");
			if (inventoryExists && static_cast<PlayerInfo*>(currentPeer->data)->UpdateFinished)
			{

				static_cast<PlayerInfo*>(currentPeer->data)->UpdateFinished = false;



				if (conn3 != nullptr)
				{
					stringstream sse;
					sse << "SELECT * FROM inventory WHERE username = '" + username + "'";
					auto query = sse.str();
					auto q = query.c_str();



					if (mysql_query(conn3, q))
					{
						cout << mysql_errno(conn3) << endl;
						cout << mysql_error(conn3) << endl;

						string ers = mysql_error(conn3);
						if (ers.find("Lost connection") != string::npos)
						{
							conn3 = mysql_init(nullptr);
							unsigned int mysql_ct;
							mysql_ct = 28800;
							mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
							conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
							if (conn3 != nullptr)
							{
								SendConsole("Connection to mysql successfully! (UpdateInventoryThread)", "MYSQL");
								Connected = true;
							}
							else
							{
								SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
								Connected = false;
							}
						}

						continue;
					}
					string Update;
					string Data;
					res3 = mysql_store_result(conn3);
					while (row = mysql_fetch_row(res3))
					{
						Data = row[2];
						Update = row[3];
					}
					mysql_free_result(res3);










					if (Update == "false" || Update == "")
					{
						string invdata;
						try
						{
							ifstream ifff("inventory/" + username + ".json");
							json j;
							ifff >> invdata;
							if (Update == "false")
							{
								stringstream ss;
								ss << "UPDATE inventory SET data = '" + invdata + "' WHERE username = '" + username + "'";
								auto query = ss.str();
								const auto q = query.c_str();
								if (mysql_query(conn3, q))
								{
									cout << mysql_errno(conn3) << endl;
									cout << mysql_error(conn3) << endl;

									string ers = mysql_error(conn3);
									if (ers.find("Lost connection") != string::npos)
									{
										conn3 = mysql_init(nullptr);
										unsigned int mysql_ct;
										mysql_ct = 28800;
										mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
										conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
										if (conn3 != nullptr)
										{
											SendConsole("Connection to mysql successfully! (UpdateInventoryThread)", "MYSQL");
											Connected = true;
										}
										else
										{
											SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
											Connected = false;
										}
									}
								}
							}
							else
							{
								stringstream ss1;
								ss1 << "INSERT INTO inventory(username, data, upd, webcoins) VALUES ('" + username + "', '" + invdata + "', 'false', '0')";
								auto query3 = ss1.str();
								auto q2 = query3.c_str();
								if (mysql_query(conn3, q2))
								{
									cout << mysql_errno(conn3) << endl;
									cout << mysql_error(conn3) << endl;

									string ers = mysql_error(conn3);
									if (ers.find("Lost connection") != string::npos)
									{
										conn3 = mysql_init(nullptr);
										unsigned int mysql_ct;
										mysql_ct = 28800;
										mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
										conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
										if (conn3 != nullptr)
										{
											SendConsole("Connection to mysql successfully! (UpdateInventoryThread)", "MYSQL");
											Connected = true;
										}
										else
										{
											SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
											Connected = false;
										}
									}
									continue;
								}
							}
							ifff.close();
						}
						catch (std::exception&)
						{
							SendConsole("UpdateInventory Critical error", "ERROR");
							continue;
						}
					}
					else if (Update == "true")
					{
						try
						{
							size_t pos;
							while ((pos = Data.find(" ")) != std::string::npos) {
								Data.replace(pos, 1, "");
							}
							std::ofstream oo("inventory/" + username + ".json");
							if (!oo.is_open()) continue;
							oo << Data << std::endl;
							oo.close();
						}
						catch (std::exception&)
						{
							SendConsole("UpdateInventory Critical error", "ERROR");
						}
						catch (std::runtime_error&)
						{
							SendConsole("UpdateInventory Critical error", "ERROR");
						}
						catch (...)
						{
							SendConsole("UpdateInventory Critical error", "ERROR");
						}
						stringstream ss;
						ss << "UPDATE inventory SET upd = 'false' WHERE username = '" + username + "'";
						auto query = ss.str();
						const auto q = query.c_str();
						if (mysql_query(conn3, q))
						{
							cout << mysql_errno(conn3) << endl;
							cout << mysql_error(conn3) << endl;

							string ers = mysql_error(conn3);
							if (ers.find("Lost connection") != string::npos)
							{
								conn3 = mysql_init(nullptr);
								unsigned int mysql_ct;
								mysql_ct = 28800;
								mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
								conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
								if (conn3 != nullptr)
								{
									SendConsole("Connection to mysql successfully! (UpdateInventoryThread)", "MYSQL");
									Connected = true;
								}
								else
								{
									SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
									Connected = false;
								}
							}
						}

						try
						{
							std::ifstream ifff("inventory/" + username + ".json");
							if (ifff.fail())
							{
								ifff.close();
							}
							if (ifff.is_open())
							{
							}
							json j;
							ifff >> j;
							if (j["items"][0]["itemid"] != 18 || j["items"][1]["itemid"] != 32)
							{
								j["items"][0]["itemid"] = 18;
								j["items"][1]["itemid"] = 32;
								j["items"][0]["quantity"] = 1;
								j["items"][1]["quantity"] = 1;
								std::ofstream oo("inventory/" + username + ".json");
								if (!oo.is_open()) continue;
								oo << j << std::endl;
							}
							PlayerInventory inventory;
							{
								InventoryItem item;
								for (int i = 0; i < static_cast<PlayerInfo*>(currentPeer->data)->currentInventorySize; i++)
								{
									int itemid = j["items"][i]["itemid"];
									int quantity = j["items"][i]["quantity"];
									if (itemid != 0 && quantity != 0)
									{
										item.itemCount = quantity;
										item.itemID = itemid;
										inventory.items.push_back(item);
									}
								}
							}
							SendInventory(currentPeer, inventory);
							static_cast<PlayerInfo*>(currentPeer->data)->inventory = inventory;
							ifff.close();
						}
						catch (...)
						{
							Player::OnConsoleMessage(currentPeer, "It appears that this account inventory is corrupted, please message Sebia#0001!");
							enet_peer_disconnect_later(currentPeer, 0);
							continue;
						}
						const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(currentPeer->data))->cloth_hair, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_shirt, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_pants), (static_cast<PlayerInfo*>(currentPeer->data))->cloth_feet, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_face, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_hand), (static_cast<PlayerInfo*>(currentPeer->data))->cloth_back, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_mask, (static_cast<PlayerInfo*>(currentPeer->data))->cloth_necklace), (static_cast<PlayerInfo*>(currentPeer->data))->skinColor), (static_cast<PlayerInfo*>(currentPeer->data))->cloth_ances, 0.0f, 0.0f));
						memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(currentPeer->data))->netID), 4);
						const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
						enet_peer_send(currentPeer, 0, packet);
						delete p3.data;

						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_hair);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_shirt);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_pants);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_feet);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_face);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_hand);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_back);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_mask);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_necklace);
						updateplayerset(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->cloth_ances);
					}
				}
				static_cast<PlayerInfo*>(currentPeer->data)->UpdateFinished = true;
			}
		}

		//mysql_close(conn3);
	}*/
}


inline void UpdateInventoryThread(ENetPeer* peer, string username, int itemid = 0, int count = 0, bool remove = false)
{
	/*auto inventoryExists = std::experimental::filesystem::exists("inventory/" + username + ".json");
	if (inventoryExists && static_cast<PlayerInfo*>(peer->data)->UpdateFinished)
	{
		cout << static_cast<PlayerInfo*>(peer->data)->rawName << endl;
		static_cast<PlayerInfo*>(peer->data)->UpdateFinished = false;
		conn3 = mysql_init(nullptr);
		unsigned int mysql_ct;
		mysql_ct = 28800;
		mysql_options(conn3, MYSQL_OPT_CONNECT_TIMEOUT, &mysql_ct);
		conn3 = mysql_real_connect(conn3, ip, user, pass, database, 0, nullptr, 0);
		if (conn3 == nullptr) return;
		if (conn3 != nullptr)
		{
			Connected = true;
		}
		else
		{
			SendConsole("Connection to mysql has failed! (UpdateInventoryThread)", "MYSQL");
			Connected = false;
			return;
		}

		if (conn3 != nullptr)
		{
			MYSQL_ROW row;
			stringstream sse;
			sse << "SELECT * FROM inventory WHERE username = '" + username + "'";
			auto query = sse.str();
			auto q = query.c_str();
			if (mysql_query(conn3, q))
			{
				cout << mysql_errno(conn3) << endl;
				cout << mysql_error(conn3) << endl;
				return;
			}
			string Update;
			string Data;
			res3 = mysql_store_result(conn3);
			while (row = mysql_fetch_row(res3))
			{
				Data = row[2];
				Update = row[3];
			}
			mysql_free_result(res3);

			if (Update == "false" || Update == "") 
			{
				string invdata;
				ifstream ifff("inventory/" + username + ".json");
				json j;
				ifff >> invdata;
				if (Update == "false")
				{
					stringstream ss;
					ss << "UPDATE inventory SET data = '" + invdata + "' WHERE username = '" + username + "'";
					auto query = ss.str();
					const auto q = query.c_str();
					if (mysql_query(conn3, q))
					{
						cout << mysql_errno(conn3) << endl;
						cout << mysql_error(conn3) << endl;
					}
				}
				else
				{
					stringstream ss1;
					ss1 << "INSERT INTO inventory(username, data, upd, webcoins) VALUES ('" + username + "', '" + invdata + "', 'false', '0')";
					auto query3 = ss1.str();
					auto q2 = query3.c_str();
					if (mysql_query(conn3, q2))
					{
						cout << mysql_errno(conn3) << endl;
						cout << mysql_error(conn3) << endl;
						return;
					}
				}
				ifff.close();
			}
			else if (Update == "true") 
			{
				try
				{
					std::ofstream oo("inventory/" + username + ".json");
					if (!oo.is_open()) return;
					oo << Data << std::endl;
					oo.close();
				}
				catch (std::exception&)
				{
					SendConsole("UpdateInventory Critical error", "ERROR");
				}
				catch (std::runtime_error&)
				{
					SendConsole("UpdateInventory Critical error", "ERROR");
				}
				catch (...)
				{
					SendConsole("UpdateInventory Critical error", "ERROR");
				}
				stringstream ss;
				ss << "UPDATE inventory SET upd = 'false' WHERE username = '" + username + "'";
				auto query = ss.str();
				const auto q = query.c_str();
				if (mysql_query(conn3, q))
				{
					cout << mysql_errno(conn3) << endl;
					cout << mysql_error(conn3) << endl;
				}
				for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
				{
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
					if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == username)
					{
						try
						{
							std::ifstream ifff("inventory/" + username + ".json");
							if (ifff.fail())
							{
								ifff.close();
							}
							if (ifff.is_open())
							{
							}
							json j;
							ifff >> j;
							if (j["items"][0]["itemid"] != 18 || j["items"][1]["itemid"] != 32)
							{
								j["items"][0]["itemid"] = 18;
								j["items"][1]["itemid"] = 32;
								j["items"][0]["quantity"] = 1;
								j["items"][1]["quantity"] = 1;
								std::ofstream oo("inventory/" + username + ".json");
								if (!oo.is_open()) return;
								oo << j << std::endl;
							}
							PlayerInventory inventory;
							{
								InventoryItem item;
								for (int i = 0; i < static_cast<PlayerInfo*>(currentPeer->data)->currentInventorySize; i++)
								{
									int itemid = j["items"][i]["itemid"];
									int quantity = j["items"][i]["quantity"];
									if (itemid != 0 && quantity != 0)
									{
										item.itemCount = quantity;
										item.itemID = itemid;
										inventory.items.push_back(item);
									}
								}
							}
							SendInventory(currentPeer, inventory);
							static_cast<PlayerInfo*>(currentPeer->data)->inventory = inventory;
							if (itemid != 0 && count != 0 && remove)
							{

								int fItemid = itemid;
								int fQuantity = count;
								try
								{
									std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
									json jj;
									if (iffff.fail())
									{
										iffff.close();
										cout << " RemoveInventoryItem funkcijoje (ofstream dalyje) error: itemid - " << fItemid << ", kiekis - " << fQuantity << endl;
									}
									if (iffff.is_open())
									{
									}
									iffff >> jj;
									std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
									if (!oo.is_open()) return;
									for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
									{
										int itemid = jj["items"][i]["itemid"];
										int quantity = jj["items"][i]["quantity"];
										if (itemid == fItemid)
										{
											if (quantity - fQuantity == 0)
											{
												jj["items"][i]["itemid"] = 0;
												jj["items"][i]["quantity"] = 0;
											}
											else
											{
												jj["items"][i]["itemid"] = itemid;
												jj["items"][i]["quantity"] = quantity - fQuantity;
											}
											break;
										}
									}
									oo << jj << std::endl;
									for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
									{
										if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
										{
											if (static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) > fQuantity && static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) != fQuantity)
											{
												static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount -= fQuantity;
											}
											else
											{
												static_cast<PlayerInfo*>(peer->data)->inventory.items.erase(static_cast<PlayerInfo*>(peer->data)->inventory.items.begin() + i);
											}
											SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
											const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
											memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
											const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
											enet_peer_send(peer, 0, packet);
										}
									}
									string invdata;
									ifstream ifff("inventory/" + username + ".json");
									json j;
									ifff >> invdata;
									stringstream ss;
									ss << "UPDATE inventory SET data = '" + invdata + "' WHERE username = '" + username + "'";
									auto query = ss.str();
									const auto q = query.c_str();
									if (mysql_query(conn3, q))
									{
										cout << mysql_errno(conn3) << endl;
										cout << mysql_error(conn3) << endl;
									}
								}
								catch (std::exception&)
								{
									SendConsole("RemoveInventoryItem Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
									if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
								}
								catch (std::runtime_error&)
								{
									SendConsole("RemoveInventoryItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
									if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
								}
								catch (...)
								{
									SendConsole("RemoveInventoryItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
									if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
								}
							}
							else if (itemid != 0 && count != 0 && !remove)
							{

								int fItemid = itemid;
								int fQuantity = count;
								bool success = true;

								size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
								auto alreadyhave = false;
								if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee && CheckItemExists(peer, fItemid) == false)
								{
									auto xx = static_cast<PlayerInfo*>(peer->data)->x;
									auto netid = -1;
									auto yy = static_cast<PlayerInfo*>(peer->data)->y;
									//DropItem(peer, netid, xx, yy, fItemid, fQuantity, 0);
									alreadyhave = true;
								}
								auto isFullStock = false;
								auto isInInv = false;
								for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
								{
									if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 200)
									{
										Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! You already have full stock of this item!|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
										isFullStock = true;
									}
									if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount < 200) isInInv = true;
								}
								if (isFullStock == true || alreadyhave == true)
								{
									success = false;
								}
								else
								{
									success = true;

									try
									{
										std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
										json jj;
										if (iffff.fail())
										{
											iffff.close();
										}
										if (iffff.is_open())
										{
										}
										iffff >> jj;
										std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
										if (!oo.is_open()) return;
										if (isInInv == false)
										{
											for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
											{
												int itemid = jj["items"][i]["itemid"];
												int quantity = jj["items"][i]["quantity"];
												if (itemid == 0 && quantity == 0)
												{
													jj["items"][i]["itemid"] = fItemid;
													jj["items"][i]["quantity"] = fQuantity;
													break;
												}
											}
											oo << jj << std::endl;
											InventoryItem item;
											item.itemID = fItemid;
											item.itemCount = fQuantity;
											static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
											SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
										}
										else
										{
											for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
											{
												int itemid = jj["items"][i]["itemid"];
												int quantity = jj["items"][i]["quantity"];
												if (itemid == fItemid)
												{
													jj["items"][i]["quantity"] = quantity + fQuantity;
													break;
												}
											}
											oo << jj << std::endl;
											for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
											{
												if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
												{
													static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount += fQuantity;
													SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
												}
											}
										}
										// update items
										const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
										memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
										const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
										enet_peer_send(peer, 0, packet);
										string invdata;
										ifstream ifff("inventory/" + username + ".json");
										json j;
										ifff >> invdata;
										stringstream ss;
										ss << "UPDATE inventory SET data = '" + invdata + "' WHERE username = '" + username + "'";
										auto query = ss.str();
										const auto q = query.c_str();
										if (mysql_query(conn3, q))
										{
											cout << mysql_errno(conn3) << endl;
											cout << mysql_error(conn3) << endl;
										}
									}
									catch (std::exception&)
									{
										SendConsole("SaveItemMoreTimes Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (std::runtime_error&)
									{
										SendConsole("SaveItemMoreTimes Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
									catch (...)
									{
										SendConsole("SaveItemMoreTimes Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
										if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
									}
								}
							}
						}
						catch (...)
						{
							Player::OnConsoleMessage(currentPeer, "It appears that this account inventory is corrupted, please message Sebia#0001!");
							enet_peer_disconnect_later(currentPeer, 0);
						}
					}
				}
			}
			mysql_close(conn3);
		}
		static_cast<PlayerInfo*>(peer->data)->UpdateFinished = true;
	}*/
}

inline void UpdateInventory(ENetPeer* peer, string username, int itemid = 0, int count = 0, bool remove = false)
{
	//thread UpdInv(UpdateInventoryThread, peer, username, itemid, count, remove);
	//if (UpdInv.joinable()) UpdInv.detach();
}

inline void checkTimeBan(ENetPeer* peer, string username)
{
	auto exist = experimental::filesystem::exists("timebanned/" + PlayerDB::getProperName(username) + ".txt");
	if (exist)
	{
		ifstream fd("timebanned/" + PlayerDB::getProperName(username) + ".txt");
		long long banDuration = 0;
		string bannedBy;
		string bannedReason;
		if (fd.fail())
		{
			cout << "[Stream-ERROR]: failed to check whether '" + username + "' is time banned." << endl;
			Player::OnConsoleMessage(peer, "`5[Stream-ERROR]: `@ failed to check whether '" + username + "' is time banned. `5Please send this screenshot to GTOS developers.");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_later(peer, 0);
		}
		else
		{
			fd >> banDuration;
			fd >> bannedBy;
			fd.ignore();
			getline(fd, bannedReason);
			fd.close();
		}
		auto bantimeleft = calcBanDuration(banDuration);
		if (bantimeleft < 1) return;
		auto text = "action|log\nmsg|`4Sorry, this account is temporary banned by `w" + bannedBy + " `4for `w" + OutputBanTime(calcBanDuration(banDuration)) + " `4for `w" + bannedReason + ". `4Need help? `8Contact Sebia#0001!";
		string dc = "https://discord.gg/VSkajzV";
		auto url = "action|set_url\nurl|" + dc + "\nlabel|Join GTOS Discord\n";
		auto data = new BYTE[5 + text.length()];
		auto* dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		delete data;
		delete dataurl;
		static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
	}
}

inline bool EventWorld(ENetPeer* peer2, string WorldName)
{
	return static_cast<PlayerInfo*>(peer2->data)->currentWorld == WorldName;
}

inline void autoBan(ENetPeer* peer, bool isInvalid, long long timeInH, string infoText)
{
	SendConsole("Player(" + static_cast<PlayerInfo*>(peer->data)->rawName + ") Duration(" + to_string(timeInH) + "h) Reason(" + infoText + ")", "BAN");
	string name;
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId == true)
	{
		name = static_cast<PlayerInfo*>(peer->data)->rawName;
	}
	else
	{
		name = "PLAYER WITHOUT GROW-ID";
	}
	char clientConnection[16];
	enet_address_get_host_ip(&peer->address, clientConnection, 16);
	string hisIp = clientConnection;
	ofstream autobanLog("logs/autoban.txt", ios::app);
	autobanLog << "[IP: " << hisIp << "], " << "[Ip_id: " << peer->address.host << "], " << name << " auto-banned for " << infoText << endl;
	autobanLog.close();
	ENetPeer* currentPeer;
	for (currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		Player::OnConsoleMessage(currentPeer, "`4** `o" + name + " `4AUTO-BANNED BY SYSTEM **`o (/rules to view rules)");
	}
	auto registermac = static_cast<PlayerInfo*>(peer->data)->registermac;
	auto registerrid = static_cast<PlayerInfo*>(peer->data)->registerrid;
	auto registersid = static_cast<PlayerInfo*>(peer->data)->registersid;
	auto registergid = static_cast<PlayerInfo*>(peer->data)->registergid;
	auto registervid = static_cast<PlayerInfo*>(peer->data)->registervid;
	auto registeraid = static_cast<PlayerInfo*>(peer->data)->registeraid;
	auto registerIP = static_cast<PlayerInfo*>(peer->data)->registerIP;
	if (registermac != "02:00:00:00:00:00" && registermac != "" && registermac != "none")
	{
		Remove(registermac, ":");
		std::ofstream outfile2("ipbans/mac/" + registermac + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registerrid != "" && registerrid != "none")
	{
		std::ofstream outfile2("ipbans/rid/" + registerrid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registersid != "" && registersid != "none")
	{
		std::ofstream outfile2("ipbans/sid/" + registersid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registergid != "" && registergid != "none")
	{
		std::ofstream outfile2("ipbans/gid/" + registergid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registervid != "" && registervid != "none")
	{
		std::ofstream outfile2("ipbans/vid/" + registervid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registeraid != "" && registeraid != "none")
	{
		std::ofstream outfile2("ipbans/aid/" + registeraid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registerIP != "" && registerIP != "none")
	{
		std::ofstream outfile2("ipbans/ip/" + registerIP + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_later(peer, 0);
}

inline void checkAutoBan(ENetPeer* peer)
{
	auto rid = static_cast<PlayerInfo*>(peer->data)->rid;
	auto sid = static_cast<PlayerInfo*>(peer->data)->sid;
	auto gid = static_cast<PlayerInfo*>(peer->data)->gid;
	auto vid = static_cast<PlayerInfo*>(peer->data)->vid;
	auto aid = static_cast<PlayerInfo*>(peer->data)->aid;
	auto mac = static_cast<PlayerInfo*>(peer->data)->mac;
	auto ip = to_string(peer->address.host);
	Remove(mac, ":");
	auto exist = experimental::filesystem::exists("autoban/rid/" + rid + ".txt") || experimental::filesystem::exists("autoban/gid/" + gid + ".txt") || experimental::filesystem::exists("autoban/vid/" + vid + ".txt") || experimental::filesystem::exists("autoban/aid/" + aid + ".txt") || experimental::filesystem::exists("autoban/ip/" + ip + ".txt");
	if (exist)
	{
		string content = "0";
		if (experimental::filesystem::exists("autoban/ip/" + ip + ".txt"))
		{
			ifstream ifs("autoban/ip/" + ip + ".txt");
			if (ifs.fail())
			{
				cout << "[Stream-ERROR]: failed to check whether '" + static_cast<PlayerInfo*>(peer->data)->rawName + "' is auto banned by system." << endl;
				Player::OnConsoleMessage(peer, "`5[Stream-ERROR]: `@ failed to check whether '" + static_cast<PlayerInfo*>(peer->data)->rawName + "' is auto banned by system. `5Please send this screenshot to GTOS developers.");
				if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_later(peer, 0);
			}
			else
			{
				ifs >> content;
				ifs.close();
			}
		}
		if (content != "0")
		{
			long long banDuration = atoi(content.c_str());
			banLoginDevice(peer, banDuration, sid, mac);
		}
	}
}

inline void checkIpBan(ENetPeer* peer)
{
	auto rid = static_cast<PlayerInfo*>(peer->data)->rid;
	auto sid = static_cast<PlayerInfo*>(peer->data)->sid;
	auto gid = static_cast<PlayerInfo*>(peer->data)->gid;
	auto vid = static_cast<PlayerInfo*>(peer->data)->vid;
	auto aid = static_cast<PlayerInfo*>(peer->data)->aid;
	auto mac = static_cast<PlayerInfo*>(peer->data)->mac;
	Remove(mac, ":");
	auto ip_id = to_string(peer->address.host);
	char clientConnection[16];
	enet_address_get_host_ip(&peer->address, clientConnection, 16);
	string ip = clientConnection;
	auto exist = experimental::filesystem::exists("ipbans/rid/" + rid + ".txt") || experimental::filesystem::exists("ipbans/gid/" + gid + ".txt") || experimental::filesystem::exists("ipbans/vid/" + vid + ".txt") || experimental::filesystem::exists("ipbans/aid/" + aid + ".txt") || experimental::filesystem::exists("ipbans/sid/" + sid + ".txt") || experimental::filesystem::exists("ipbans/mac/" + mac + ".txt") || experimental::filesystem::exists("ipbans/ip_id/" + ip_id + ".txt") || experimental::filesystem::exists("ipbans/ip/" + ip + ".txt");
	if (exist)
	{
		string text = "action|log\nmsg|`4Sorry, this device or location is perma banned. Need help? Contact `2Sebia#0001!";
		string text3 = "action|logon_fail\n";
		string dc = "https://discord.gg/VSkajzV";
		auto url = "action|set_url\nurl|" + dc + "\nlabel|Join GTOS Discord\n";
		auto data = new BYTE[5 + text.length()];
		auto data3 = new BYTE[5 + text3.length()];
		auto dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		memcpy(data3, &type, 4);
		memcpy(data3 + 4, text3.c_str(), text3.length());
		memcpy(data3 + 4 + text3.length(), &zero, 1);
		auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		auto p2 = enet_packet_create(data3, 5 + text3.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p2);
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_later(peer, 0);
		delete data;
		delete dataurl;
		delete data3;
	}
}

inline int PlayerDB::playerLogin(ENetPeer* peer, string username, string password)
{
	if (serverIsFrozen) return -4;
	auto uname = username;
	toUpperCase(uname);
	auto username1 = static_cast<PlayerInfo*>(peer->data)->tankIDName;
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos) return -10;
	if (username.length() < 3) return -2;
	if (username.length() > 20) return -2;
	if (uname == "" || uname == " " || uname == "  " || uname == "   " || uname == "    ") return -5;
	if (username == "prn" || username == "con" || username == "aux" || username == "nul" || username == "com1" || username == "com2" || username == "com3" || username == "com4" || username == "com5" || username == "com6" || username == "com7" || username == "com8" || username == "com9" || username == "lpt1" || username == "lpt2" || username == "lpt3" || username == "lpt4" || username == "lpt5" || username == "lpt6" || username == "lpt7" || username == "lpt8" || username == "lpt9")
	{
		return -5;
	}
	if (username1.find(" ") != string::npos || username1.find(".") != string::npos || username1.find(",") != string::npos || username1.find("@") != string::npos || username1.find("?") != string::npos || username1.find("[") != string::npos || username1.find("]") != string::npos || username1.find("#") != string::npos || username1.find("<") != string::npos || username1.find(">") != string::npos || username1.find(":") != string::npos || username1.find("{") != string::npos || username1.find("}") != string::npos || username1.find("|") != string::npos || username1.find("+") != string::npos || username1.find("_") != string::npos || username1.find("~") != string::npos || username1.find("-") != string::npos || username1.find("!") != string::npos || username1.find("$") != string::npos || username1.find("%") != string::npos || username1.find("^") != string::npos || username1.find("&") != string::npos || username1.find("`") != string::npos || username1.find("*") != string::npos || username1.find("(") != string::npos || username1.find(")") != string::npos || username1.find("=") != string::npos || username1.find("'") != string::npos || username1.find(";") != string::npos || username1.find("/") != string::npos) return -5;
	ifstream get_maintenance("maintenance.json");
	if (get_maintenance.fail())
	{
		get_maintenance.close();
		return -7;
	}
	json maintenance_json;
	get_maintenance >> maintenance_json;
	get_maintenance.close();

	if (maintenance_json["enable"] == 1)
	{
		bool is_white_listed = false;
		for (int i = 0; i < maintenance_json["whitelist"].size(); i++)
		{
			if (maintenance_json["whitelist"][i] == PlayerDB::getProperName(username))
			{
				is_white_listed = true;
				break;
			}
		}
		if (!is_white_listed)
		{
			return -7;
		}
	}
	auto rid = static_cast<PlayerInfo*>(peer->data)->rid;
	auto sid = static_cast<PlayerInfo*>(peer->data)->sid;
	auto gid = static_cast<PlayerInfo*>(peer->data)->gid;
	auto vid = static_cast<PlayerInfo*>(peer->data)->vid;
	auto aid = static_cast<PlayerInfo*>(peer->data)->aid;
	auto mac = static_cast<PlayerInfo*>(peer->data)->mac;
	char clientConnection[16];
	enet_address_get_host_ip(&peer->address, clientConnection, 16);
	string ipe = clientConnection;
	Remove(mac, ":");
	auto exist = experimental::filesystem::exists("autoban/rid/" + rid + ".txt") || experimental::filesystem::exists("autoban/gid/" + gid + ".txt") || experimental::filesystem::exists("autoban/vid/" + vid + ".txt") || experimental::filesystem::exists("autoban/aid/" + aid + ".txt") || experimental::filesystem::exists("autoban/ip/" + ipe + ".txt");
	if (exist) return -10;
	auto ip_id = to_string(peer->address.host);
	auto existtwo = experimental::filesystem::exists("ipbans/rid/" + rid + ".txt") || experimental::filesystem::exists("ipbans/gid/" + gid + ".txt") || experimental::filesystem::exists("ipbans/vid/" + vid + ".txt") || experimental::filesystem::exists("ipbans/aid/" + aid + ".txt") || experimental::filesystem::exists("ipbans/sid/" + sid + ".txt") || experimental::filesystem::exists("ipbans/mac/" + mac + ".txt") || experimental::filesystem::exists("ipbans/ip_id/" + ip_id + ".txt") || experimental::filesystem::exists("ipbans/ip/" + ipe + ".txt");
	if (existtwo) return -9;
	auto effectexist = std::experimental::filesystem::exists("misc/effect/" + PlayerDB::getProperName(username) + ".txt");
	if (!effectexist)
	{
		ofstream eff("misc/effect/" + PlayerDB::getProperName(username) + ".txt");
		eff << 8421376;
		eff.close();
	}
	MYSQL_ROW row;
	stringstream sse;
	sse << "SELECT * FROM PlayerDatabase WHERE username = '" + username + "'";
	auto query = sse.str();
	auto q = query.c_str();
	if (mysql_query(conn, q))
	{
				string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
		cout << mysql_error(conn) << endl;
		return 0;
	}
	string Password;
	string InventorySize;
	string DailyRewards;
	string Skill;
	string Banned;
	res = mysql_store_result(conn);
	// ReSharper disable once CppUsingResultOfAssignmentAsCondition
	while (row = mysql_fetch_row(res))
	{
		Password = row[2];
		static_cast<PlayerInfo*>(peer->data)->email = row[3];
		InventorySize = row[27];
		Skill = row[28];
		DailyRewards = row[29];
		Banned = row[14];
	}
	mysql_free_result(res);

	if (password == Password)
	{
		if (Banned == "1") return -3;
		stringstream basic_stringstream;
		basic_stringstream << "SELECT * FROM aap WHERE growid = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
		if (!basic_stringstream.fail())
		{
			auto mystr = basic_stringstream.str();
			auto strings = mystr.c_str();
			if (mysql_query(conn, strings))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return 0;
			}
		}
		string connectionip;
		string verified;
		string growid;
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			growid = row[1];
			connectionip = row[3];
			verified = row[4];
		}
		mysql_free_result(res);

		if (growid.size() == 0)
		{
			stringstream ss1;
			ss1 << "INSERT INTO aap(growid, code, ip, verified) VALUES ('" + static_cast<PlayerInfo*>(peer->data)->rawName + "', '', '" + static_cast<PlayerInfo*>(peer->data)->charIP + "', 'true')";
			auto query3 = ss1.str();
			auto q2 = query3.c_str();
			if (mysql_query(conn, q2))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return 0;
			}
		}
		if (connectionip != static_cast<PlayerInfo*>(peer->data)->charIP && static_cast<PlayerInfo*>(peer->data)->charIP  != "127.0.0.1" || verified == "false" && static_cast<PlayerInfo*>(peer->data)->charIP != "127.0.0.1") return -6;
		auto exist = experimental::filesystem::exists("timebanned/" + PlayerDB::getProperName(username) + ".txt");
		if (exist) return -8;
		ENetPeer* net_peer;
		for (net_peer = server->peers; net_peer < &server->peers[server->peerCount]; ++net_peer)
		{
			if (net_peer->state != ENET_PEER_STATE_CONNECTED) continue;
			if (net_peer == peer) continue;
			if (static_cast<PlayerInfo*>(net_peer->data)->rawName == PlayerDB::getProperName(username))
			{
				if (static_cast<PlayerInfo*>(peer->data)->Console || static_cast<PlayerInfo*>(net_peer->data)->Console)
				{
					Player::OnConsoleMessage(net_peer, "Someone has logged in to your account via Console!");
				}
				else
				{
					Player::OnConsoleMessage(net_peer, "Someone else was logged into this account!");
					enet_host_flush(server);
					enet_peer_disconnect_later(net_peer, 0);
				}
			}
		}
		static_cast<PlayerInfo*>(peer->data)->currentInventorySize = atoi(InventorySize.c_str());
		static_cast<PlayerInfo*>(peer->data)->skill = Skill;
		static_cast<PlayerInfo*>(peer->data)->lastdailyGems = atoi(DailyRewards.c_str());
		return 1;
	}
	else return -1;
}

inline int PlayerDB::playerRegister(ENetPeer* peer, string username, string password, string email)
{
	if (serverIsFrozen) return -1;
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos) return -10;
	if (email.find("@") == string::npos || email.length() <= 0 || email.length() > 30) return -15;
	if (username.length() < 3) return -2;
	if (username.length() > 20) return -2;
	if (username == "" || username == " " || username == "  " || username == "   " || username == "    ") return -11;
	if (username == "prn" || username == "con" || username == "aux" || username == "nul" || username == "com1" || username == "com2" || username == "com3" || username == "com4" || username == "com5" || username == "com6" || username == "com7" || username == "com8" || username == "com9" || username == "lpt1" || username == "lpt2" || username == "lpt3" || username == "lpt4" || username == "lpt5" || username == "lpt6" || username == "lpt7" || username == "lpt8" || username == "lpt9")
	{
		return -11;
	}
	username = PlayerDB::getProperName(username);
	auto existGems = std::experimental::filesystem::exists("gemdb/" + username + ".txt");
	if (!existGems)
	{
		ofstream pGems("gemdb/" + username + ".txt");
		pGems << 0;
		pGems.close();
	}
	MYSQL_ROW row;
	if (conn == nullptr)
	{
		cout << "null" << endl;
		return -16;
	}
	if (conn != nullptr)
	{
		stringstream sse;
		string name;
		sse << "SELECT * FROM PlayerDatabase WHERE username = '" + username + "'";
		auto query = sse.str();
		auto q = query.c_str();
		if (mysql_query(conn, q))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return 0;
		}
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			name = row[1];
		}
		mysql_free_result(res);

		if (name.length() > 0)
		{
			return -1;
		}
		short registeringIpCount = 1;
		auto existsRegisteringIP = std::experimental::filesystem::exists("registeredIP/" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
		if (existsRegisteringIP)
		{
			ifstream getIp("registeredIP/" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
			getIp >> registeringIpCount;
			registeringIpCount += 1;
			if (registeringIpCount >= 4) return -14;
			ofstream writeIp("registeredIP/" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
			writeIp << registeringIpCount;
			writeIp.close();
		}
		else
		{
			ofstream writeIp("registeredIP/" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
			writeIp << 1;
			writeIp.close();
		}
		char clientConnection[16];
		enet_address_get_host_ip(&peer->address, clientConnection, 16);
		string hisIp = clientConnection;
		stringstream ss;
		ss << "INSERT INTO PlayerDatabase(username, password, email, ClothBack, ClothHand, ClothFace, ClothShirt, ClothPants, ClothNeck, ClothHair, ClothFeet, ClothMask, ClothAnces, isBanned, ipID, effect, friends, receivedwarns, adminLevel, guild, joinguild, level, xp, worldsowned, notebook, kills, inventorysize, skill, dailyrewards, lastonline, online, mac, rid, sid, gid, vid, aid, ip, subtype, subdate, title) VALUES ('" + username + "', '" + password + "', '" + email + "', '" + std::to_string(0) + "', '" + std::to_string(0) + "', '" + std::to_string(0) + "', '" + std::to_string(0) + "', '0', '0', '0', '0', '" + std::to_string(0) + "', '0', '0', '8421376', '', '', '" + to_string(static_cast<PlayerInfo*>(peer->data)->warns) + "', '0', '', 'false', '1', '0', '', '', '0', '30', 'None', '0', '0', 'false', '" + static_cast<PlayerInfo*>(peer->data)->mac + "', '" + static_cast<PlayerInfo*>(peer->data)->rid + "', '" + static_cast<PlayerInfo*>(peer->data)->sid + "', '" + static_cast<PlayerInfo*>(peer->data)->gid + "', '" + static_cast<PlayerInfo*>(peer->data)->vid + "', '" + static_cast<PlayerInfo*>(peer->data)->aid + "', '" + hisIp + "', '', '', '')";
		auto query3 = ss.str();
		auto qsd = query3.c_str();
		if (mysql_query(conn, qsd))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return 0;
		}
		stringstream ss1;
		ss1 << "INSERT INTO aap(growid, code, ip, verified) VALUES ('" + username + "', '', '" + static_cast<PlayerInfo*>(peer->data)->charIP + "', 'true')";
		auto query3s = ss1.str();
		auto q2 = query3s.c_str();
		if (mysql_query(conn, q2))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return 0;
		}
		stringstream basic_stringstream;
		basic_stringstream << "INSERT INTO PlayerState(username, nick, invis, ghost, skin, chatcolor) VALUES ('" + username + "', '', 'false', 'false', '0x8295C3FF', '')";
		auto cs = basic_stringstream.str();
		auto str = cs.c_str();
		if (mysql_query(conn, str))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return 0;
		}
	}
	else
	{
		return -16;
	}
	return 1;
}

vector<Admin> admins;

inline int adminlevel(const string name)
{
	MYSQL_ROW row;
	if (conn == nullptr)
	{
		cout << "null" << endl;
		return 0;
	}
	if (conn != nullptr)
	{
		stringstream sse;
		sse << "SELECT * FROM PlayerDatabase WHERE username = '" + name + "'";
		const auto query = sse.str();
		const auto q = query.c_str();
		if (mysql_query(conn, q))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return 0;
		}
		string AdminLevel;
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			AdminLevel = row[19];
		}
		mysql_free_result(res);

		return atoi(AdminLevel.c_str());
	}
	else
	{
		return 0;
	}
}

inline bool isDev(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isMod(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel == 1 || static_cast<PlayerInfo*>(peer->data)->adminLevel == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isPlayer(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isRedAnces(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5084 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5180 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5182 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5184 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5186 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5188)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isGreenAnces(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5082 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5162 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5164 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5166 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5168 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5170)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isBlueAnces(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5080 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5144 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5146 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5148 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5150 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5152)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isYellowAnces(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5078 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5126 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5128 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5130 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5132 || static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5134)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isFishingRod(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 2912 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3008 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3010 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3040 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3100 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 5740)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline string getModsOnlineCount()
{
	auto modCount = 0;
	string text = "No mods are online";
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isMod(currentPeer))
		{
			modCount++;
		}
	}
	if (modCount == 1)
	{
		text = to_string(modCount) + " mod is online";
	}
	if (modCount > 1)
	{
		text = to_string(modCount) + " mods are online";
	}
	return text;
}

inline void showModLogs(const string textInfo)
{
	auto p6 = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), textInfo));
	const string text = "action|play_sfx\nfile|audio/beep.wav\ndelayMS|0\n";
	const auto data = new BYTE[5 + text.length()];
	BYTE zero = 0;
	auto type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (!static_cast<PlayerInfo*>(currentPeer->data)->radio) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == "EXIT") continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isIn == false) continue;
		if (isMod(currentPeer))
		{
			const auto packet6 = enet_packet_create(p6.data, p6.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet6);
			const auto packet2 = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet2);
		}
	}
	delete data;
	delete p6.data;
}

inline void AutoDemote(string playerName, string his_rank, string ipAddress, string whyDemote)
{
	if (playerName == "sebia" || playerName == "robertasltu") return;
	if (conn == nullptr)
	{
		cout << "conn was nullptr" << endl;
		return;
	}
	if (conn != nullptr)
	{
		stringstream ss;
		ss << "UPDATE PlayerDatabase SET adminLevel = '0' WHERE username = '" + playerName + "'";
		auto query = ss.str();
		const auto q = query.c_str();
		if (mysql_query(conn, q))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return;
		}
	}
	ofstream autodemoteLog("logs/autodemote.txt", ios::app);
	autodemoteLog << "[" << ipAddress << "] administrator " << playerName << " with rank: " + his_rank + " auto-demoted for: " << whyDemote << endl;
	autodemoteLog.close();
	ENetPeer* currentPeer;
	for (currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == playerName)
		{
			if (!static_cast<PlayerInfo*>(currentPeer->data)->Console) enet_peer_disconnect_later(currentPeer, 0);
		}
	}
}

inline void GiveRank(string rankName, string playerName, bool& success)
{
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	if (conn == nullptr)
	{
		cout << "conn was nullptr" << endl;
		success = false;
		return;
	}
	if (conn != nullptr)
	{
		int rankLevel = 0;

		if (rankName == "player")
		{
			rankLevel = 0;
		}
		else if (rankName == "mod")
		{
			rankLevel = 1;
		}
		else if (rankName == "dev")
		{
			rankLevel = 2;
		}
		stringstream ss;
		ss << "UPDATE PlayerDatabase SET adminLevel = '" + to_string(rankLevel) + "' WHERE username = '" + playerName + "'";
		const auto query = ss.str();
		const auto q = query.c_str();
		if (mysql_query(conn, q))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			
			
			return;
		}
		success = true;
	}
}

inline bool SaveConvertedItemDls(int fItemid, int fQuantity, ENetPeer* peer)
{
	bool doesItemInInventryAlready = false;
	for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items[i].itemID == fItemid)
		{
			doesItemInInventryAlready = true;
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items[i].itemCount >= 101) return false;
			break;
		}
	}
	try
	{
		std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		json jj;
		if (iffff.fail())
		{
			iffff.close();
			cout << "SaveConvertedItem funkcijoje (ifstream dalyje) error: itemid - " << fItemid << ", kiekis - " << fQuantity << endl;
		}
		if (iffff.is_open())
		{
		}
		iffff >> jj;
		std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		if (!oo.is_open()) return true;
		int howManyHasNow = 0;
		for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
		{
			int itemidFromJson = jj["items"][i]["itemid"];
			int quantityFromJson = jj["items"][i]["quantity"];;
			if (doesItemInInventryAlready)
			{
				if (itemidFromJson == fItemid)
				{
					howManyHasNow = jj["items"][i]["quantity"];
					howManyHasNow += fQuantity;
					jj["items"][i]["quantity"] = howManyHasNow;
					for (int k = 0; k < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); k++)
					{
						if (static_cast<PlayerInfo*>(peer->data)->inventory.items[k].itemID == fItemid)
						{
							static_cast<PlayerInfo*>(peer->data)->inventory.items[k].itemCount += static_cast<short>(fQuantity);
							break;
						}
					}
					SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
					const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
					memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
					const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
					enet_peer_send(peer, 0, packet);
					break;
				}
			}
			else if (itemidFromJson == 0 && quantityFromJson == 0)
			{
				jj["items"][i]["quantity"] = fQuantity;
				jj["items"][i]["itemid"] = fItemid;
				InventoryItem item;
				item.itemID = fItemid;
				item.itemCount = fQuantity;
				static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
				SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				break;
			}
		}
		oo << jj << std::endl;
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
	}
	catch (std::exception&)
	{
		SendConsole("SaveConvertedItemDls Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (std::runtime_error&)
	{
		SendConsole("SaveConvertedItemDls Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (...)
	{
		SendConsole("SaveConvertedItemDls Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	return true;
}

inline bool SaveConvertedItem(int fItemid, int fQuantity, ENetPeer* peer)
{
	bool doesItemInInventryAlready = false;
	for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items[i].itemID == fItemid)
		{
			doesItemInInventryAlready = true;
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items[i].itemCount >= 200) return false;
			break;
		}
	}
	try
	{
		std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		json jj;
		if (iffff.fail())
		{
			iffff.close();
			cout << "SaveConvertedItem funkcijoje (ifstream dalyje) error: itemid - " << fItemid << ", kiekis - " << fQuantity << endl;
		}
		if (iffff.is_open())
		{
		}
		iffff >> jj;
		std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		if (!oo.is_open()) return true;
		auto howManyHasNow = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
		{
			int itemidFromJson = jj["items"][i]["itemid"];
			int quantityFromJson = jj["items"][i]["quantity"];;
			if (doesItemInInventryAlready)
			{
				if (itemidFromJson == fItemid)
				{
					howManyHasNow = jj["items"][i]["quantity"];
					howManyHasNow += fQuantity;
					jj["items"][i]["quantity"] = howManyHasNow;
					for (int k = 0; k < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); k++)
					{
						if (static_cast<PlayerInfo*>(peer->data)->inventory.items[k].itemID == fItemid)
						{
							static_cast<PlayerInfo*>(peer->data)->inventory.items[k].itemCount += static_cast<BYTE>(fQuantity);
							break;
						}
					}
					SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
					break;
				}
			}
			else if (itemidFromJson == 0 && quantityFromJson == 0)
			{
				jj["items"][i]["quantity"] = fQuantity;
				jj["items"][i]["itemid"] = fItemid;
				InventoryItem item;
				item.itemID = fItemid;
				item.itemCount = fQuantity;
				static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
				SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
				memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
				const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet);
				break;
			}
		}
		oo << jj << std::endl;
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
	}
	catch (std::exception&)
	{
		SendConsole("SaveConvertedItem Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (std::runtime_error&)
	{
		SendConsole("SaveConvertedItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (...)
	{
		SendConsole("SaveConvertedItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	return true;
}

inline void SaveShopsItem(int fItemid, int fQuantity, ENetPeer* peer, bool& success)
{
	size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
	auto alreadyhave = false;
	if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee)
	{
		auto ps = packetEnd(appendString(appendString(createPacket(), "OnDialogRequest"), "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! Your inventory is full! You can purchase an inventory upgrade in the shop.|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|"));
		auto packet = enet_packet_create(ps.data, ps.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete ps.data;
		alreadyhave = true;
	}
	auto iscontains = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
		{
			auto ps = packetEnd(appendString(appendString(createPacket(), "OnDialogRequest"), "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! Your inventory already contains this item!|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|"));
			auto packet = enet_packet_create(ps.data, ps.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet);
			delete ps.data;
			iscontains = true;
		}
	}
	if (iscontains == true || alreadyhave == true)
	{
		success = false;
	}
	else
	{
		success = true;
		try
		{
			std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			json jj;
			if (iffff.fail())
			{
				iffff.close();
				cout << "SaveShopsItem funkcijoje (ifstream dalyje) error: itemid - " << fItemid << ", kiekis - " << fQuantity << endl;
			}
			if (iffff.is_open())
			{
			}
			iffff >> jj;
			std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			if (!oo.is_open()) return;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
			{
				int itemid = jj["items"][i]["itemid"];
				int quantity = jj["items"][i]["quantity"];
				if (itemid == 0 && quantity == 0)
				{
					jj["items"][i]["itemid"] = fItemid;
					jj["items"][i]["quantity"] = fQuantity;
					break;
				}
			}
			oo << jj << std::endl;
			InventoryItem item;
			item.itemID = fItemid;
			item.itemCount = fQuantity;
			static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
			SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
			const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
			memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
			const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet);
			UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
		}
		catch (std::exception&)
		{
			SendConsole("SaveShopsItem Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (std::runtime_error&)
		{
			SendConsole("SaveShopsItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (...)
		{
			SendConsole("SaveShopsItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
	}
}

inline bool CheckItemMaxed(ENetPeer* peer, const int fItemId, const int fQuantityAdd)
{
	auto isMaxed = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount + fQuantityAdd > 200)
		{
			isMaxed = true;
			break;
		}
	}
	return isMaxed;
}

inline int GetQuantityOfItem(ENetPeer* peer, const int fItemId)
{
	auto quantity = 0;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId)
		{
			quantity = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			break;
		}
	}
	return quantity;
}

inline void SaveFindsItem(int fItemid, int fQuantity, ENetPeer* peer)
{
	try
	{
		std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		json jj;
		if (iffff.fail())
		{
			iffff.close();
		}
		if (iffff.is_open())
		{
		}
		iffff >> jj;
		std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		if (!oo.is_open()) return;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
		{
			int itemid = jj["items"][i]["itemid"];
			int quantity = jj["items"][i]["quantity"];
			if (itemid == 0 && quantity == 0)
			{
				jj["items"][i]["itemid"] = fItemid;
				jj["items"][i]["quantity"] = fQuantity;
				break;
			}
		}
		oo << jj << std::endl;
		InventoryItem item;
		item.itemID = fItemid;
		item.itemCount = fQuantity;
		static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
		SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
		const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
		memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
		const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
	}
	catch (std::exception&)
	{
		SendConsole("SaveFindsItem Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (std::runtime_error&)
	{
		SendConsole("SaveFindsItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (...)
	{
		SendConsole("SaveFindsItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
}

inline void RemoveInventoryItem(int fItemid, int fQuantity, ENetPeer* peer, bool update)
{
	try
	{
		std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		json jj;
		if (iffff.fail())
		{
			iffff.close();
			cout << " RemoveInventoryItem funkcijoje (ofstream dalyje) error: itemid - " << fItemid << ", kiekis - " << fQuantity << endl;
		}
		if (iffff.is_open())
		{
		}
		iffff >> jj;
		std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		if (!oo.is_open()) return;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
		{
			int itemid = jj["items"][i]["itemid"];
			int quantity = jj["items"][i]["quantity"];
			if (itemid == fItemid)
			{
				if (quantity - fQuantity == 0)
				{
					jj["items"][i]["itemid"] = 0;
					jj["items"][i]["quantity"] = 0;
				}
				else
				{
					jj["items"][i]["itemid"] = itemid;
					jj["items"][i]["quantity"] = quantity - fQuantity;
				}
				break;
			}
		}
		oo << jj << std::endl;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
			{
				if (static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) > fQuantity && static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) != fQuantity)
				{
					static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount -= fQuantity;
				}
				else
				{
					static_cast<PlayerInfo*>(peer->data)->inventory.items.erase(static_cast<PlayerInfo*>(peer->data)->inventory.items.begin() + i);
				}
				SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				if (update)
				{
					const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
					memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
					const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
					enet_peer_send(peer, 0, packet);
				}
			}
		}
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity, true);
	}
	catch (std::exception&)
	{
		SendConsole("RemoveInventoryItem Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (std::runtime_error&)
	{
		SendConsole("RemoveInventoryItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (...)
	{
		SendConsole("RemoveInventoryItem Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
}

inline void SaveInventoryWhenBuildingBlock(ENetPeer* peer, int itemid)
{
	try
	{
		std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		json jj;
		if (iffff.fail())
		{
			iffff.close();
			cout << "Klaida, skaitant inventoriu zaidejui " << static_cast<PlayerInfo*>(peer->data)->rawName << " jam statant bloka worlde!" << endl;
		}
		if (iffff.is_open())
		{
		}
		iffff >> jj;
		std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
		if (!oo.is_open()) return;
		for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
		{
			if (i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size())
			{
				jj["items"][i]["itemid"] = static_cast<unsigned>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID);
				jj["items"][i]["quantity"] = static_cast<unsigned>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount);
			}
			else
			{
				jj["items"][i]["itemid"] = 0;
				jj["items"][i]["quantity"] = 0;
			}
		}
		oo << jj << std::endl;
		if (oo.fail())
		{
			oo.close();
		}
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, itemid, 1, true);
	}
	catch (std::exception&)
	{
		SendConsole("SaveInventoryWhenBuildingBlock Critical error details: rawName(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (std::runtime_error&)
	{
		SendConsole("SaveInventoryWhenBuildingBlock Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
	catch (...)
	{
		SendConsole("SaveInventoryWhenBuildingBlock Critical error details: name(" + static_cast<PlayerInfo*>(peer->data)->rawName + ")", "ERROR");
		if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
	}
}

inline void GetPlayerFragments(string playerName, int& fEarth, int& fDark, int& fFire, int& fWater)
{
	ifstream fd("fragments/" + playerName + ".txt");
	fd >> fEarth;
	fd >> fDark;
	fd >> fFire;
	fd >> fWater;
	fd.close();
}

inline void AddPlayerFragmentEarth(ENetPeer* peer, int count)
{
	int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	const int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	const int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriEarth += count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fEarth = dabarTuriEarth;
}

inline void AddPlayerFragmentDark(ENetPeer* peer, int count)
{
	const int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	const int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriDark += count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fDark = dabarTuriDark;
}

inline void RemovePlayerFragmentDark(ENetPeer* peer, int count)
{
	const int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	const int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriDark -= count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fDark = dabarTuriDark;
}

inline void RemovePlayerFragmentFire(ENetPeer* peer, int count)
{
	const int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	const int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriFire -= count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fFire = dabarTuriFire;
}

inline void RemovePlayerFragmentEarth(ENetPeer* peer, int count)
{
	int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	const int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	const int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriEarth -= count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fEarth = dabarTuriEarth;
}

inline void AddPlayerFragmentFire(ENetPeer* peer, int count)
{
	const int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	const int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	const int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriFire += count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fFire = dabarTuriFire;
}

inline void AddPlayerFragmentWater(ENetPeer* peer, int count)
{
	const int dabarTuriEarth = static_cast<PlayerInfo*>(peer->data)->fEarth;
	const int dabarTuriDark = static_cast<PlayerInfo*>(peer->data)->fDark;
	const int dabarTuriFire = static_cast<PlayerInfo*>(peer->data)->fFire;
	int dabarTuriWater = static_cast<PlayerInfo*>(peer->data)->fWater;
	ofstream ofrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	dabarTuriWater += count;
	ofrgm << dabarTuriEarth << endl;
	ofrgm << dabarTuriDark << endl;
	ofrgm << dabarTuriFire << endl;
	ofrgm << dabarTuriWater << endl;
	ofrgm.close();
	static_cast<PlayerInfo*>(peer->data)->fWater = dabarTuriWater;
}

inline void UpdateLocalPlayerFragments(ENetPeer* peer)
{
	ifstream ifrgm("fragments/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	ifrgm >> static_cast<PlayerInfo*>(peer->data)->fEarth;
	ifrgm >> static_cast<PlayerInfo*>(peer->data)->fDark;
	ifrgm >> static_cast<PlayerInfo*>(peer->data)->fFire;
	ifrgm >> static_cast<PlayerInfo*>(peer->data)->fWater;
	ifrgm.close();
}

inline void GiveChestPrizeGems(ENetPeer* peer, int gemsAmount)
{
	int currentGems = 0;
	ifstream ifs("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	ifs >> currentGems;
	ifs.close();
	currentGems += gemsAmount;
	ofstream ofs("gemdb/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	ofs << currentGems;
	ofs.close();
	GamePacket pp = packetEnd(appendInt(appendString(createPacket(), "OnSetBux"), currentGems));
	ENetPacket* packetpp = enet_packet_create(pp.data,
		pp.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packetpp);
	delete pp.data;
	Player::OnConsoleMessage(peer, "`^You have obtained `9" + to_string(gemsAmount) + "`# Gems`^!");
	Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`q" + static_cast<PlayerInfo*>(peer->data)->displayName + " `^Have obtained `9" + to_string(gemsAmount) + " `#Gems`^!", 0, true);
	const int effect = 30;
	const int x = static_cast<PlayerInfo*>(peer->data)->x;
	const int y = static_cast<PlayerInfo*>(peer->data)->y;
	Player::OnParticleEffect(peer, effect, x, y, 0);
}

inline void onPeerConnect(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->Console) return;
	for (ENetPeer* currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
			continue;
		if (peer != currentPeer)
		{
			if (isHere(peer, currentPeer))
			{
				if (static_cast<PlayerInfo*>(currentPeer->data)->Console) continue;
				string netIdS = std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->netID);
				GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnSpawn"), "spawn|avatar\nnetID|" + netIdS + "\nuserID|" + netIdS + "\ncolrect|0|0|20|30\nposXY|" + std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->x) + "|" + std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->y) + "\nname|``" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "``\ncountry|" + static_cast<PlayerInfo*>(currentPeer->data)->country + "\ninvis|0\nmstate|0\nsmstate|0\n")); // ((PlayerInfo*)(server->peers[i].data))->tankIDName
				ENetPacket* packet = enet_packet_create(p.data,
					p.len,
					ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet);
				delete p.data;
				string netIdS2 = std::to_string(static_cast<PlayerInfo*>(peer->data)->netID);
				GamePacket p2 = packetEnd(appendString(appendString(createPacket(), "OnSpawn"), "spawn|avatar\nnetID|" + netIdS2 + "\nuserID|" + netIdS2 + "\ncolrect|0|0|20|30\nposXY|" + std::to_string(static_cast<PlayerInfo*>(peer->data)->x) + "|" + std::to_string(static_cast<PlayerInfo*>(peer->data)->y) + "\nname|``" + static_cast<PlayerInfo*>(peer->data)->displayName + "``\ncountry|" + static_cast<PlayerInfo*>(peer->data)->country + "\ninvis|0\nmstate|0\nsmstate|0\n")); // ((PlayerInfo*)(server->peers[i].data))->tankIDName
				ENetPacket* packet2 = enet_packet_create(p2.data,
					p2.len,
					ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2);
				delete p2.data;
			}
		}
	}
}
inline void sendSound(ENetPeer* peer, const string sound)
{
	const auto text = "action|play_sfx\nfile|audio/" + sound + "\ndelayMS|0\n";
	const auto data = new BYTE[5 + text.length()];
	BYTE zero = 0;
	auto type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	const auto packet2 = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet2);
	delete data;
}
inline void sendTime(ENetPeer* peer)
{
	using namespace std::chrono;
	string curseText = "none";
	string muteText = "none";
	if (std::experimental::filesystem::exists("cursedplayers/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt"))
	{
		curseText = "`4Curse expires in `2" + OutputBanTime(calcBanDuration(static_cast<PlayerInfo*>(peer->data)->lastCursed)) + "";
	}
	if (std::experimental::filesystem::exists("timemuted/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt"))
	{
		muteText = "`4Mute expires in `2" + OutputBanTime(calcBanDuration(static_cast<PlayerInfo*>(peer->data)->lastMuted)) + "";
	}
	auto _tm = time(nullptr);
	// ReSharper disable once CppDeprecatedEntity
	const auto curtime = localtime(&_tm);
	// ReSharper disable once CppDeprecatedEntity
	const string test = asctime(curtime);
	GamePacket p;
	if (curseText == "none" && muteText == "none")
	{
		p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`2Current time is: " + test + "`7You are not `bcursed `7and `bmuted"));
	}
	else if (curseText != "none" && muteText == "none")
	{
		p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`2Current time is: " + test + "`4You are `bcursed!\n" + curseText + ""));
	}
	else if (curseText == "none" && muteText != "none")
	{
		p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`2Current time is: " + test + "`4You are `bmuted!\n" + muteText + ""));
	}
	else
	{
		p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`2Current time is: " + test + "`4You are `bcursed `4and `bmuted!\n" + curseText + "\n" + muteText));
	}
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void updateInvis(ENetPeer* peer)
{
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer))
		{
			auto p2 = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), static_cast<PlayerInfo*>(peer->data)->isinv));
			memcpy(p2.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet2);
			delete p2.data;
			auto p3 = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), static_cast<PlayerInfo*>(currentPeer->data)->isinv));
			memcpy(p3.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet3);
			delete p3.data;
			if (static_cast<PlayerInfo*>(peer->data)->adminLevel == 0)
			{
			}
			if (static_cast<PlayerInfo*>(peer->data)->level >= 100)
			{
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			}
			else
			{
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			}
			const auto flag1 = (65536 * static_cast<PlayerInfo*>(peer->data)->guildBg) + static_cast<PlayerInfo*>(peer->data)->guildFg;
			if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == static_cast<PlayerInfo*>(currentPeer->data)->guildLeader)
			{
				auto p2gg = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag1), 0));
				memcpy(p2gg.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2gg = enet_packet_create(p2gg.data, p2gg.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2gg);
				delete p2gg.data;
				const auto flag2 = (65536 * static_cast<PlayerInfo*>(currentPeer->data)->guildBg) + static_cast<PlayerInfo*>(currentPeer->data)->guildFg;
				auto p2xd = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag2), 0));
				memcpy(p2xd.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2xd = enet_packet_create(p2xd.data, p2xd.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2xd);
				delete p2xd.data;
			}
			else
			{
				auto p2gg = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag1), 0));
				memcpy(p2gg.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2gg = enet_packet_create(p2gg.data, p2gg.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2gg);
				delete p2gg.data;
				const auto flag2 = (65536 * static_cast<PlayerInfo*>(currentPeer->data)->guildBg) + static_cast<PlayerInfo*>(currentPeer->data)->guildFg;
				auto p2xd = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag2), 0));
				memcpy(p2xd.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2xd = enet_packet_create(p2xd.data, p2xd.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2xd);
				delete p2xd.data;
			}
		}
	}
}

inline void sendnews(ENetPeer* peer)
{
	//string news = "set_default_color|\n\nadd_label_with_icon|big|`5GTOS`w `@1.0``|left|5956|noflags|0|0|\n\nadd_image_button|okgo|interface/large/menu_photo.rttex|noflags|||\n\nadd_spacer|\nadd_label_with_icon|small|`8Harvest Festival`^! Added So Much `9Things `^To `9Explore`^, lets start from `6Harvesting Trees`^, during this `9Event `^Harvesting any type of `9Tree `^Has a Chance to drop any mooncake, depending on `9Tree Rarity`^, Added new `#Chemical Combiner `9Recipes`^, can be found in our `cDiscord`^, Also added `9Feature `^to Disable Collecting Dropped Items for Visitors, This `9Option `^Can be `@Configured `^In `9World Locks`^ Menu By `2World Owners. Homever This `cEvent `^Only `9Active `^During Specified `#Date And Time`^!|left|1056|\n\nadd_spacer|\nadd_label_with_icon|small|`#Chemical Combiners`^! This `9Update `^Brings `9Ability `^To `@Create `^New Items Using `#Chemical Combiners `^Such as `4Laboratory`^ And others, `9Recipes `^Are being added daily and will be announced in `cDiscord`^!|left|912|\n\nadd_spacer|\nadd_label_with_icon|small|`4Triple Place Potion`^! Gives you `9Ability `^To `@Triple Place `^Any `9Farmable Block `^For `c5 Minutes `^Duration, `9Obtainable `2Currently `^Via `c/buy `^For `@60 `2World Locks`^!|left|6924|\n\nadd_spacer|\nadd_label_with_icon|small|`#Dreamcatcher Staff`^! This `9Awesome `^Item gives you `@30% `^Chance to obtain `4Extra `cDrop `^When `9Harvesting `^Seeds, `9Obtainable `^Only from `c/buy `^For `@1200 `2World Locks`^!|left|6840|\n\nadd_spacer|\nadd_label_with_icon|small|`4One HIT Potion`^! The very first `9Potion `^In Our `9Server`^, Gives you `9Ability `^To `@One HIT `^Any `9Farmable Block `^For `c5 Minutes `^Duration, Can be `9Combined `^With Rayman And other items, `9Obtainable `2Currently `^Via `c/buy `^For `@80 `2World Locks`^, But most likely in `9Future `^It will be moved to the `#Alchemia! `^Update`^!|left|6918|\n\nadd_spacer|\nadd_label_with_icon|small|`cUnstable Tesseract`^! This `9Block `^Allows you To `9Collect Any Block `^You want, but the capacity is limited to `@1500 `^And no `cRemote `^Included, available from `c/buy `^For `@300 `$World Locks`^!|left|6948|\n\nadd_spacer|\nadd_label_with_icon|small|`cGaia's Beacon`^! This `9Block `^Allows you To `9Collect Any Seed `^You want, but the capacity is limited to `@1500 `^And no `cRemote `^Included, available from `c/buy `^For `@900 `$World Locks`^!|left|6946|\n\nadd_spacer|\nadd_label_with_icon|small|`6Citrine Block`^! This is the new `9Farmable`^, Which can give you even up to `@3000 `2Gems`^, `^More `9Information `^Can be found in the `4Store`^!|left|10028|\n\nadd_spacer|\nadd_label_with_icon|small|`#Special Events`^! This `9Update `^Brings `#Event System `^This is how it works: An `9Event `^Occurs every `@10 `2Minutes `^And in randomly choosen `9World`^!|left|7186|\n\nadd_spacer|\nadd_label_with_icon|small|`4Item Rarities`^! This `9Update `^Brings a `cRarity System `^For the `@Custom Items`^, More `9Information `^Can be found in our `#Discord`^!|left|752|\n\nadd_spacer|\nadd_label_with_icon|small|`cStore Linker`^! This `9Update `^Added a `9Change `^For the `#Vending Machines `^And now they can be used to link your `4Store `^To the `#Machine `^To make `9Players easier find it`^!|left|2978|\n\nadd_spacer|\nadd_label_with_icon|small|`2Marketplace`^! This `9Update `^Brings a `4Huge `^Change to the `4Store `^By `9Replacing `^It with a `2Marketplace`^, From now all `9Players `^Can have their own `4Store`^, More information can be found in `cDiscord`^!|left|7990|\n\nadd_spacer|\nadd_label_with_icon|small|`8Guild Rewards Season II`^! This `9Update `^Brings new `6Rewards `^And `6Features `^To the `8Guildrewards`^, added `cPersonal Contribution Rewards `^And `9Ability `^To gain `4Points `^For `6Harvesting `cTrees`^!|left|7340|\n\nadd_spacer|\nadd_label_with_icon|small|`cMagplant Remote`^! This `9Update `^Brings the `cRemote `^Feature to `cMagplants`^, which works just like its `9Supposed `^to and other `4Visual `^Improvements, Also added `9Storage `^Limits for the `cMagplant 5000`^!|left|5640|\n\nadd_spacer|\nadd_label_with_icon|small|`#The Ancestral Update`^! This `9Update `^Brings `@Major `^Changes to `cAncestrals`^, lets start from `4Ancestral Lens of Riches `^Which gives you now `9Ability `^To obtain `2Extra Gem Drops `^Higher `6Level `cAncestral `^Bigger `9Chance`^, `cAncestral Tesseract of Dimensions `^Gives you `9Ability `^To get `2Extra Block Drops`^, `9Ancestral Totem of Wisdom `^Gives you `9Ability `^To get `2Extra XP Buff `^Which is really `4Insane `^Because if you have `2Bush wings `^They will triple your `cXP Drop `^And `9Ancestral `^Will `9Double `^It once again`^!|left|7166|\n\nadd_spacer|\nadd_label_with_icon|small|`cMagplant`^! This `9Block `^Allows you To `9Collect Any Item `^You want, available from `c/buy `^For `@2600 `$World Locks`^!|left|5638|\n\nadd_spacer|\nadd_label_with_icon|small|`2Lucky Clover`^! This `9Awesome `cConsummable Item `^Gives you `4Extra Gem Drop `^For `c30 Minutes `^Duration, available `^From `c/buy `^For `@25 `$World Locks`^!|left|528|\n\nadd_spacer|\nadd_label_with_icon|small|`#Growscan`^! Added `9Ability `^To see `$Dropped Items `^And `$Gems `^In a `cWorld `^Using `#Growscan `^Which is available from `c/buy `^For `@600 `9World Locks`^!|left|6016|\n\nadd_spacer|\nadd_label_with_icon|small|`cSeeds And More`^! This `9Update `^Brings `cAbility To Splice And Grow Seeds `^Also `$Dropped Items `^Are now saved `2Permanently`^!|left|120|\n\nadd_spacer|\nadd_label_with_icon|small|`$Summerfest`^! This `9Update `^Brings `@100+ `^Real Growtopia New `cItems `^And `#Nightmare Vampire Cape `^Which is made by `cOther`^, And available from `c/buy `^For `@4000 `$World Locks`^!|left|10004|\n\nadd_spacer|\nadd_label_with_icon|small|`cTrade Feature`^! Finally we added a `cTrade `^Into `cGTOS `^And `9Fixed `^All bugs, trade is now fully working and `@Safe `^To use`^!|left|1424|\n\nadd_spacer|\nadd_label_with_icon|small|`#Play Cat Hair`^! New `cItem `^Designed By `@Shiino `^Available from `c/buy `^For `@12 `!Diamond Locks`^!|left|10018|\n\nadd_spacer|\nadd_label_with_icon|small|`4Nightmare Blood Wings`^! New `cItem `^Designed By `@Fads `^Available from `c/buy `^For `@35 `!Diamond Locks`^, Gives double jump `9Effect`^!|left|10016|\n\nadd_spacer|\nadd_label_with_icon|small|`cSoul Scythe`^! New `cItem `^Designed By `@Shiino `^Available from `c/buy `^For `@15 `!Diamond Locks`^, Gives 1 HIT Break, and `9Effect`^!|left|10014|\n\nadd_spacer|\nadd_label_with_icon|small|`4Phoenix Angel Wings`^! New `cItem `^Designed By `@Shirogane `^Available from `c/buy `^For `@18 `!Diamond Locks`^, Gives double jump `9Effect`^!|left|10012|\n\nadd_spacer|\nadd_label_with_icon|small|`cAdvanced Display Blocks`^! This `9Update `^Brings `2Huge Changes `^To The `cDisplay Block `^Now all items that are stored in `cDisplay Blocks `^Can be `@Removed`^, Also addiding an item into `cDisplay Block `^Will `@Remove `^It from your `9Inventory`^!|left|2946|\n\nadd_spacer|\nadd_label_with_icon|small|`cAll Items Paid`^! This `9Update `@Removed `cThe Find Feature `^That means all `cItems `^Now costs `$World Locks`^, To access the `cBuy Menu `^Write `c/buy`^!|left|752|\n\nadd_spacer|\nadd_label_with_icon|small|`#Legendary Wizard`^! This `9Update `^Added a lot of new `9Content `^To Explore, A new `2Quests `^System, which can be accessed via the `#Legendary Wizard`^, Which is `9Obtainable `^From the `4Store `^For `43 `1Blue Gem locks `^And is `@Untradable`^, `@Untrashable`^, `@Undrobable`^. Theres currently available `2Quest `^For the `wStar Wings`^!|left|1790|\n\nadd_spacer|\nadd_label_with_icon|small|`@Anti Gravity`^! This `9Update `^Brings new `@Anti Gravity `^To The `4Store `^Which is available for `@30 `2World Locks`^, also `9Balance Changes`^!|left|4992|\n\nadd_spacer|\nadd_label_with_icon|small|`8Summer Update`^! This `9Update `^Brings you the `25th `^Guild Reward, Fixed `4Trade `^System, New `#Broadcasts `^System, `8Magic Machine `^Now `2Supports `^All Farmables`^!|left|836|\n\nadd_spacer|\nadd_label_with_icon|small|`9Geiger Update`^! This `9Update `^Brings a lot of new `9Content `^Including `wGeiger Counter `^And new `8Yellow Crystal `^Which is available for `2Green Crystal's `^And can be `2Purchased `^By using `2Telephone `^And dialing `@12345 `^Number`^!|left|9510|\n\nadd_spacer|\nadd_label_with_icon|small|`8Guild Rewards`^! This `9Update `^Is Big, Firstly we `9Added `^New feature called `8GRewards `^Which can be found in the `5Social Portal `^You can `9Obtain `8GPoints `^By `9Magic Machine `^Or Breaking `9Farmable Blocks`^, `8GPoints `^Can be `9Exchanged `^Into `9Awesome `^Rewards`^!|left|7340|\n\nadd_spacer|\nadd_label_with_icon|small|`9GStokens`^! Added New `8Currency `^Called `9Golden `@Store Tokens `^Which are `9Obtainable `^For `4100 `2Regular `4Tokens`^, By buying a `9GStoken `^Theres no way going back`^!|left|9500|\n\nadd_spacer|\nadd_label_with_icon|small|`4Ruby Shards`^! Those shards can be `9Used `^To obtain `4Ruby Lock`^, `9Requires `@200 `4Shards`^!|left|4426|\n\nadd_spacer|\nadd_label_with_icon|small|`#Pink Diamond`^! This is the new `9Farmable`^, Which can give you even up to `@3000 `2Gems`^, also a `9Chance `^To obtain `4Ruby Shards `^More `9Information `^Can be found in the `4Store`^!|left|10024|\n\nadd_spacer|\nadd_label_with_icon|small|`3UFO `!Helmet`^! Another new `9Levelup `^Reward, Available for free if you are `1Level `@10 `^Or Higher, This item has most `9Beautiful `^Animations`^!|left|9498|\n\nadd_spacer|\nadd_label_with_icon|small|`4Demon `2Turtle Hat`^! A New `9Levelup `^Reward have been added to the `5Growpedia `^This item can be `9Obtained `^For free if you are `1Level `@50 `^Or `9Higher`^!|left|9492|\n\nadd_spacer|\nadd_label_with_icon|small|`eDual Blades`^! New `9Military `^Knife, Obtainable from `9Armory Store `^For `@60 `1Diamond Locks `^Rarity `8Legendary`^!|left|9494|\n\nadd_spacer|\nadd_label_with_icon|small|`2Tree Block`^! In This `9Update `^We have added new `9Block `^Called `2Tree Block `^Available from breaking `^Bush or Hedge `9Blocks`^, And much things were `2Improved `^In this `9Update`^!|left|9490|\n\nadd_spacer|\nadd_label_with_icon|small|`9WOTW Trophy`^! Exclusive Item, Obtainable only for `8Most Awesome Worlds `^Submit your `9Worlds `^In our `5Discord`^!|left|9488|\n\nadd_spacer|\nadd_label_with_icon|small|`@Kill Rewards`^! This `9Update `^Brings new `9Feature `^To `9Exchange `^Kills into `9Awesome Rewards`^, Those `9Rewards `^Can be found in the `5Growpedia`^!|left|1976|\n\nadd_spacer|\nadd_label_with_icon|small|`8Damned Knife`^! Added the `9Very first `^Gun, which allows you to `4Kill `^Other `9Players `^More `5Information `^About this `9Knife `^Available in the `4Store`^!|left|9484|\n\nadd_spacer|\nadd_label_with_icon|small|`4HP System`^! This `9Update `^Brings a lot of new `9Content `^Firstly we added new `9Category `^To the `4Store `^Called `5Armory `^In there you can purchase stuff associated with this `9Update`^. Regular `9Players `^Has `@100 `4HP`^!|left|384|\n\nadd_spacer|\nadd_label_with_icon|small|`5Growpedia`^! Moved `9Rankup `^From `@Salesman `^To The `5Growpedia`^!|left|6336|\n\nadd_spacer|\nadd_label_with_icon|small|`9Golden Staff`^! This is the new `9Levelup Reward `^Available for free if you are `1Level `@80 `^Or higher, gives you `9Ability `^To convert `9Blocks `^To `9Gold`^!|left|9482|\n\nadd_spacer|\nadd_label_with_icon|small|\n\nadd_spacer|small|\n\nadd_url_button|comment|`9Visit GTOSPRIVATE.com Website``|noflags|http://gtosprivate.com |Visit Our Website ?|4|\n\nadd_spacer|small|0|0|)|noflags|0|0|\nnend_dialog|gazette||OK|small|\nnend_dialog|gazette||OK||left|\nadd_button|anticrash|`@Fix `4Crash `^[`2Remove Set`^]|\n\nadd_spacer|\nadd_button|okgo|`^Close|noflags|0|0|\nnend_dialog|gazette||OK|";
	//Player::OnDialogRequest(peer, news);
}

inline void updateAllClothes(ENetPeer* peer)
{
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer))
		{
			auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), static_cast<PlayerInfo*>(peer->data)->cloth_hair, static_cast<PlayerInfo*>(peer->data)->cloth_shirt, static_cast<PlayerInfo*>(peer->data)->cloth_pants), static_cast<PlayerInfo*>(peer->data)->cloth_feet, static_cast<PlayerInfo*>(peer->data)->cloth_face, static_cast<PlayerInfo*>(peer->data)->cloth_hand), static_cast<PlayerInfo*>(peer->data)->cloth_back, static_cast<PlayerInfo*>(peer->data)->cloth_mask, static_cast<PlayerInfo*>(peer->data)->cloth_necklace), static_cast<PlayerInfo*>(peer->data)->skinColor), static_cast<PlayerInfo*>(peer->data)->cloth_ances, 0.0f, 0.0f));
			memcpy(p3.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet3);
			delete p3.data;
			auto p4 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), static_cast<PlayerInfo*>(currentPeer->data)->cloth_hair, static_cast<PlayerInfo*>(currentPeer->data)->cloth_shirt, static_cast<PlayerInfo*>(currentPeer->data)->cloth_pants), static_cast<PlayerInfo*>(currentPeer->data)->cloth_feet, static_cast<PlayerInfo*>(currentPeer->data)->cloth_face, static_cast<PlayerInfo*>(currentPeer->data)->cloth_hand), static_cast<PlayerInfo*>(currentPeer->data)->cloth_back, static_cast<PlayerInfo*>(currentPeer->data)->cloth_mask, static_cast<PlayerInfo*>(currentPeer->data)->cloth_necklace), static_cast<PlayerInfo*>(currentPeer->data)->skinColor), static_cast<PlayerInfo*>(currentPeer->data)->cloth_ances, 0.0f, 0.0f));
			memcpy(p4.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
			const auto packet4 = enet_packet_create(p4.data, p4.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet4);
			delete p4.data;
		}
	}
}

inline void showWrong(ENetPeer* peer, string listFull, string itemFind)
{
	Player::OnDialogRequest(peer, "add_label_with_icon|big|`9Find item: " + itemFind + "``|left|3146|\n" + listFull + "add_textbox|Enter a word below to find the item|\nadd_text_input|item|Item Name||30|\nend_dialog|findid|Cancel|Find the item!|\n");
}

inline void SaveShopsItemMoreTimesLoginis(int fItemid, int fQuantity, ENetPeer* peer, bool& success)
{
	size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
	auto alreadyhave = false;
	if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee)
	{
		Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! Your inventory is full! You can purchase an inventory upgrade in the shop.|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
		alreadyhave = true;
	}
	auto isFullStock = false;
	auto isInInv = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 101)
		{
			Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! You already have full stock of this item!|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
			isFullStock = true;
		}
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount < 200) isInInv = true;
	}
	if (isFullStock == true || alreadyhave == true)
	{
		success = false;
	}
	else
	{
		success = true;
		try
		{
			std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			json jj;
			if (iffff.fail())
			{
				iffff.close();
			}
			if (iffff.is_open())
			{
			}
			iffff >> jj;
			std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			if (!oo.is_open()) return;
			if (isInInv == false)
			{
				for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
				{
					int itemid = jj["items"][i]["itemid"];
					int quantity = jj["items"][i]["quantity"];
					if (itemid == 0 && quantity == 0)
					{
						jj["items"][i]["itemid"] = fItemid;
						jj["items"][i]["quantity"] = fQuantity;
						break;
					}
				}
				oo << jj << std::endl;
				InventoryItem item;
				item.itemID = fItemid;
				item.itemCount = fQuantity;
				static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
				SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
				memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
				const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet);
			}
			else
			{
				for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
				{
					int itemid = jj["items"][i]["itemid"];
					int quantity = jj["items"][i]["quantity"];
					if (itemid == fItemid)
					{
						jj["items"][i]["quantity"] = quantity + fQuantity;
						break;
					}
				}
				oo << jj << std::endl;
				for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
				{
					if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
					{
						static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount += fQuantity;
						SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
						const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
						memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
						const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
						enet_peer_send(peer, 0, packet);
					}
				}
			}
			iffff.close();
			UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
		}
		catch (std::exception&)
		{
			SendConsole("SaveShopsItemMoreTimesLoginis Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (std::runtime_error&)
		{
			SendConsole("SaveShopsItemMoreTimesLoginis Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (...)
		{
			SendConsole("SaveShopsItemMoreTimesLoginis Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
	}
}

inline void SaveShopsItemMoreTimes(int fItemid, int fQuantity, ENetPeer* peer, bool& success)
{
	size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
	auto alreadyhave = false;
	if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee)
	{
		Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! Your inventory is full! You can purchase an inventory upgrade in the shop.|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
		alreadyhave = true;
	}
	auto isFullStock = false;
	auto isInInv = false;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 200)
		{
			Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! You already have full stock of this item!|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
			isFullStock = true;
		}
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount < 200) isInInv = true;
	}
	if (isFullStock == true || alreadyhave == true)
	{
		success = false;
	}
	else
	{
		success = true;
		try
		{
			std::ifstream iffff("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			json jj;
			if (iffff.fail())
			{
				iffff.close();
			}
			if (iffff.is_open())
			{
			}
			iffff >> jj;
			std::ofstream oo("inventory/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			if (!oo.is_open()) return;
			if (isInInv == false)
			{
				for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
				{
					int itemid = jj["items"][i]["itemid"];
					int quantity = jj["items"][i]["quantity"];
					if (itemid == 0 && quantity == 0)
					{
						jj["items"][i]["itemid"] = fItemid;
						jj["items"][i]["quantity"] = fQuantity;
						break;
					}
				}
				oo << jj << std::endl;
				InventoryItem item;
				item.itemID = fItemid;
				item.itemCount = fQuantity;
				static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
				SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
				memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
				const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet);
			}
			else
			{
				for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->currentInventorySize; i++)
				{
					int itemid = jj["items"][i]["itemid"];
					int quantity = jj["items"][i]["quantity"];
					if (itemid == fItemid)
					{
						jj["items"][i]["quantity"] = quantity + fQuantity;
						break;
					}
				}
				oo << jj << std::endl;
				for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
				{
					if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid)
					{
						static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount += fQuantity;
						SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
						const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
						memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
						const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
						enet_peer_send(peer, 0, packet);
					}
				}
			}
			iffff.close();
			UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName, fItemid, fQuantity);
		}
		catch (std::exception&)
		{
			SendConsole("SaveShopsItemMoreTimes Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (std::runtime_error&)
		{
			SendConsole("SaveShopsItemMoreTimes Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
		catch (...)
		{
			SendConsole("SaveShopsItemMoreTimes Critical error", "ERROR");
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
		}
	}
}
inline void givequestkatanastep2xp(ENetPeer* peer, int amount)
{
	string cQuest = "None";
	ifstream fileStream213("quests/currentquest/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	fileStream213 >> cQuest;
	fileStream213.close();
	auto sQuest = 1;
	ifstream fileStream216("quests/currentqueststep/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	fileStream216 >> sQuest;
	fileStream216.close();
	if (cQuest == "Katana" && sQuest == 2)
	{
		auto alrdadded = 0;
		ifstream fileStream316("quests/katana/step2/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
		fileStream316 >> alrdadded;
		fileStream316.close();
		auto willaddnow = alrdadded + amount;
		ofstream fileStream219("quests/katana/step2/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
		fileStream219 << willaddnow;
		fileStream219.close();
	}
}
inline void givequestkatanastep3storetoken(ENetPeer* peer, int amount)
{
	string cQuest = "None";
	ifstream fileStream213("quests/currentquest/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	fileStream213 >> cQuest;
	fileStream213.close();
	auto sQuest = 1;
	ifstream fileStream216("quests/currentqueststep/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	fileStream216 >> sQuest;
	fileStream216.close();
	if (cQuest == "Katana" && sQuest == 3)
	{
		auto alrdadded = 0;
		ifstream fileStream316("quests/katana/step3/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
		fileStream316 >> alrdadded;
		fileStream316.close();
		auto willaddnow = alrdadded + amount;
		ofstream fileStream219("quests/katana/step3/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
		fileStream219 << willaddnow;
		fileStream219.close();
	}
}
inline void Player::OnInvis(ENetPeer* peer, const int state, int netID)
{
	GamePacket p = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), state));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnFailedToEnterWorld(ENetPeer* peer)
{
	GamePacket p = packetEnd(appendIntx(appendString(createPacket(), "OnFailedToEnterWorld"), 1));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnTextOverlay(ENetPeer* peer, string text)
{
	if (static_cast<PlayerInfo*>(peer->data)->Console)
	{
		SendPacket(peer, text.c_str());
		return;
	}
	GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnTextOverlay"), text));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnKilled(ENetPeer* peer, int netID)
{
	GamePacket p = packetEnd(appendString(createPacket(), "OnKilled"));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::SetRespawnPos(ENetPeer* peer, int posX, int posY, int netID)
{
	GamePacket p22 = packetEnd(appendInt(appendString(createPacket(), "SetRespawnPos"), posX + posY)); // (world->width * posY)
	memcpy(p22.data + 8, &netID, 4);
	ENetPacket* packet22 = enet_packet_create(p22.data,
		p22.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet22);
	delete p22.data;
}
inline void Player::OnZoomCamera(ENetPeer* peer, float value1, int value2)
{
	GamePacket p = packetEnd(appendIntx(appendFloat(appendString(createPacket(), "OnZoomCamera"), value1), value2));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::SmoothZoom(ENetPeer* peer)
{
	GamePacket p = packetEnd(appendIntx(appendFloat(appendString(createPacket(), "OnZoomCamera"), 10000.0f), 1000));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnRaceStart(ENetPeer* peer, int netID)
{
	GamePacket p = packetEnd(appendString(createPacket(), "OnRaceStart"));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnRaceEnd(ENetPeer* peer, int netID)
{
	GamePacket p = packetEnd(appendString(createPacket(), "OnRaceStart"));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::Ping(ENetPeer* peer)
{
	GamePacket p = packetEnd(appendString(createPacket(), "Ping"));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnDialogRequest(ENetPeer* peer, string args)
{
	if (static_cast<PlayerInfo*>(peer->data)->Console)
	{
		SendPacket(peer, args.c_str());
		return;
	}
	GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnDialogRequest"), args));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnSetPos(ENetPeer* peer, int netID, int x, int y)
{
	GamePacket p = packetEnd(appendFloat(appendString(createPacket(), "OnSetPos"), x, y));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnSetFreezeState(ENetPeer* peer, int state, int netID)
{
	GamePacket p = packetEnd(appendInt(appendString(createPacket(), "OnSetFreezeState"), state));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnSetCurrentWeather(ENetPeer* peer, const int weather)
{
	
	auto p = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), weather));
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnSetBux(ENetPeer* peer, const int gems, const int accountstate)
{
	
	auto p = packetEnd(appendInt(appendInt(appendString(createPacket(), "OnSetBux"), gems), accountstate));
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnParticleEffect(ENetPeer* peer, const int effect, const float x, const float y, int delay)
{
	
	auto p = packetEnd(appendFloat(appendIntx(appendString(createPacket(), "OnParticleEffect"), effect), x + 15, y + 15)); // + 15 to fix float and int things
	auto deathFlag = 0x19;
	memcpy(p.data + 24, &delay, 4);
	memcpy(p.data + 56, &deathFlag, 4);
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::SetHasGrowID(ENetPeer* peer, int status, string username, string password)
{
	
	GamePacket p2 = packetEnd(appendString(appendString(appendInt(appendString(createPacket(), "SetHasGrowID"), status), username), password));
	ENetPacket* packet2 = enet_packet_create(p2.data,
		p2.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet2);
	delete p2.data;
}
inline void Player::OnNameChanged(ENetPeer* peer, int netID, string name)
{
	GamePacket p3 = packetEnd(appendString(appendString(createPacket(), "OnNameChanged"), "`0`0" + name));
	memcpy(p3.data + 8, &netID, 4);
	ENetPacket* packet3 = enet_packet_create(p3.data,
		p3.len,
		ENET_PACKET_FLAG_RELIABLE);
	for (ENetPeer* currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
			continue;
		if (isHere(peer, currentPeer))
		{
			enet_peer_send(currentPeer, 0, packet3);
		}
	}
	delete p3.data;
}
inline void Player::OnSendToServer(ENetPeer* peer, int userID, int token, string ip, int port, string doorId, int lmode)
{
	
	auto p = packetEnd(appendInt(appendString(appendInt(appendInt(appendInt(appendString(createPacket(), "OnSendToServer"), port), token), userID), ip + "|" + doorId), lmode));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnChangeSkin(ENetPeer* peer, const int skinColor, int netID)
{
	
	auto p = packetEnd(appendInt(appendString(createPacket(), "OnChangeSkin"), skinColor));
	memcpy(p.data + 8, &netID, 4);
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnCountdownStart(ENetPeer* peer, int netID, int time, int score)
{
	
	if (score == -1)
	{
		auto p = packetEnd(appendInt(appendString(createPacket(), "OnCountdownStart"), time));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
	else
	{
		auto p = packetEnd(appendInt(appendInt(appendString(createPacket(), "OnCountdownStart"), time), score));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
}
inline void Player::OnPlayPositioned(ENetPeer* peer, string audiofile, int netID, bool broadcastInWorld, ENetPacket* pk) // packet only externally used when broadcasting / sending to multiple players to reduce memory leaks / cpu usage cuz we dont want to loop creating the packet for each player that would be insanely stupid.
{
	
	if (broadcastInWorld)
	{
		for (ENetPeer* currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
				continue;
			if (isHere(peer, currentPeer))
			{
				enet_peer_send(currentPeer, 0, pk);
			}
		}
	}
	else
	{
		auto p = packetEnd(appendString(appendString(createPacket(), "OnPlayPositioned"), audiofile));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
}

inline void Player::OnStartTrade(ENetPeer* peer, string displayName, int netID)
{
	
	auto p = packetEnd(appendInt(appendString(appendString(createPacket(), "OnStartTrade"), displayName), netID));
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnForceTradeEnd(ENetPeer* peer)
{
	
	GamePacket p = packetEnd(appendString(createPacket(), "OnForceTradeEnd"));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::PlayAudio(ENetPeer* peer, string audioFile, int delayMS)
{
	
	if (static_cast<PlayerInfo*>(peer->data)->platformID == "1") return;
	const string text = "action|play_sfx\nfile|" + audioFile + "\ndelayMS|" + to_string(delayMS) + "\n";
	BYTE* data = new BYTE[5 + text.length()];
	BYTE zero = 0;
	int type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	ENetPacket* packet = enet_packet_create(data,
		5 + text.length(),
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete data;
}
inline void Player::OnRemove(ENetPeer* peer, int netID)
{
	
	GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnRemove"), "netID|" + std::to_string(netID) + "\n"));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnConsoleMessage(ENetPeer* peer, string text)
{
	GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), text));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnTalkBubble(ENetPeer* peer, const int netID, const string text, const int chatColor, const bool isOverlay)
{
	if (text == ":)" || text == ":(" || text == ":*" || text == ":o" || text == ":O" || text == ":D") return;
	if (static_cast<PlayerInfo*>(peer->data)->Console)
	{
		Player::OnConsoleMessage(peer, text);
		return;
	}
	if (isOverlay == true)
	{
		auto p = packetEnd(appendIntx(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), netID), text), chatColor), 1));
		const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
	else
	{
		auto p = packetEnd(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), netID), text), chatColor));
		const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
}

inline void Player::OnAddNotification(ENetPeer* peer, string text, string audiosound, string interfaceimage)
{
	auto p = packetEnd(appendInt(appendString(appendString(appendString(appendString(createPacket(), "OnAddNotification"),
					interfaceimage),
				text),
			audiosound),
		0));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void sendWrongCmd(ENetPeer* peer)
{
	Player::OnConsoleMessage(peer, "`4Unknown command. `oEnter `$/help `ofor a list of valid commands.");
}

inline void LoadPlayerData(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId)
	{
		auto p = static_cast<PlayerInfo*>(peer->data);

		MYSQL_ROW row;
		stringstream sse;
		sse << "SELECT * FROM PlayerDatabase WHERE username = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
		auto query = sse.str();
		auto q = query.c_str();
		if (mysql_query(conn, q))
		{
					string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return;
		}
		string ClothBack;
		string ClothHand;
		string ClothFace;
		string ClothHair;
		string ClothFeet;
		string ClothPants;
		string ClothNeck;
		string ClothShirt;
		string ClothMask;
		string ClothAnces;
		string Friends;
		string AdminLevel;
		string Level;
		string Experience;
		string KillsCount;
		string GuildName;
		string InventorySize;
		string PersonalNote;
		string SkillName;
		string JoinedGuild;
		string subtype;
		string subdate;
		string title;
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			ClothBack = row[4];
			ClothHand = row[5];
			ClothFace = row[6];
			ClothShirt = row[7];
			ClothPants = row[8];
			ClothNeck = row[9];
			ClothHair = row[10];
			ClothFeet = row[11];
			ClothMask = row[12];
			ClothAnces = row[13];
			Friends = row[17];
			AdminLevel = row[19];
			GuildName = row[20];
			JoinedGuild = row[21];
			Level = row[22];
			Experience = row[23];
			PersonalNote = row[25];
			KillsCount = row[26];
			InventorySize = row[27];
			SkillName = row[28];
			p->registermac = row[32];
			p->registerrid = row[33];
			p->registersid = row[34];
			p->registergid = row[35];
			p->registervid = row[36];
			p->registeraid = row[37];
			p->registerIP = row[38];
			subtype = row[39];
			subdate = row[40];
			title = row[41];
		}
		mysql_free_result(res);

		if (subtype != "" && subdate != "" && subtype != "0" && subdate != "0")
		{
			p->haveSuperSupporterName = true;
			p->Subscriber = true;
			p->SubscribtionEndDay = atoi(subdate.c_str());
		}
		if (p->registermac == "" && p->registerrid == "" && p->registersid == "" && p->registergid == "" && p->registervid == "" && p->registeraid == "" && p->registerIP == "")
		{
			stringstream ss;
			ss << "UPDATE PlayerDatabase SET mac = '" + static_cast<PlayerInfo*>(peer->data)->mac + "', rid = '" + static_cast<PlayerInfo*>(peer->data)->rid + "', sid = '" + static_cast<PlayerInfo*>(peer->data)->sid + "', gid = '" + static_cast<PlayerInfo*>(peer->data)->gid + "', vid = '" + static_cast<PlayerInfo*>(peer->data)->vid + "', aid = '" + static_cast<PlayerInfo*>(peer->data)->aid + "', ip = '" + to_string(peer->address.host) + "' WHERE username = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
			auto basic_string = ss.str();
			const auto str = basic_string.c_str();
			if (mysql_query(conn, str))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return;
			}
		}
		if (p->registerIP.find('.') == std::string::npos)
		{
			char clientConnection[16];
			enet_address_get_host_ip(&peer->address, clientConnection, 16);
			string hisIp = clientConnection;
			stringstream ss;
			ss << "UPDATE PlayerDatabase SET ip = '" + hisIp + "' WHERE username = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
			auto cs = ss.str();
			const auto text = cs.c_str();
			if (mysql_query(conn, text))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return;
			}
		}
		p->adminLevel = atoi(AdminLevel.c_str());
		switch (p->adminLevel)
		{
		case 2:
			static_cast<PlayerInfo*>(peer->data)->displayName = "`6@" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			static_cast<PlayerInfo*>(peer->data)->displayNamebackup = "`6@" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			break;
		case 1:
			static_cast<PlayerInfo*>(peer->data)->displayName = "`#@" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			static_cast<PlayerInfo*>(peer->data)->displayNamebackup = "`#@" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			break;
		case 0:
			static_cast<PlayerInfo*>(peer->data)->displayName = "`w" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			static_cast<PlayerInfo*>(peer->data)->displayNamebackup = "`w" + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			break;
		default:
			if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
			break;
		}
		if (title != "" && subtype != "" && subdate != "" && subtype != "0" && subdate != "0")
		{
			static_cast<PlayerInfo*>(peer->data)->NickPrefix = title;
			static_cast<PlayerInfo*>(peer->data)->displayName = title + ". " + static_cast<PlayerInfo*>(peer->data)->tankIDName;
		}
		p->cloth_back = atoi(ClothBack.c_str());
		p->cloth_hand = atoi(ClothHand.c_str());
		p->cloth_face = atoi(ClothFace.c_str());
		p->cloth_hair = atoi(ClothHair.c_str());
		p->cloth_feet = atoi(ClothFeet.c_str());
		p->cloth_pants = atoi(ClothPants.c_str());
		p->cloth_necklace = atoi(ClothNeck.c_str());
		p->cloth_shirt = atoi(ClothShirt.c_str());
		p->cloth_mask = atoi(ClothMask.c_str());
		p->cloth_ances = atoi(ClothAnces.c_str());
		p->guild = GuildName;
		if (JoinedGuild == "false") p->joinguild = false;
		else if (JoinedGuild == "true") p->joinguild = true;
		p->level = atoi(Level.c_str());
		p->xp = atoi(Experience.c_str());
		p->notebook = PersonalNote;
		p->TotalKills = atoi(KillsCount.c_str());
		p->skill = SkillName;			
		if (p->cloth_back == 8552)
		{
			static_cast<PlayerInfo*>(peer->data)->NickPrefix = "`4Dr";
		}				
		stringstream ss(Friends);
		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			if (substr.size() == 0) continue;
			p->friendinfo.push_back(substr);
		}
		p->currentInventorySize = atoi(InventorySize.c_str());
		updateAllClothes(peer);
		PlayerInventory inventory;
		InventoryItem inventory_item;
		inventory_item.itemCount = 1;
		inventory_item.itemID = 18;
		inventory.items.push_back(inventory_item);
		inventory_item.itemCount = 1;
		inventory_item.itemID = 32;
		inventory.items.push_back(inventory_item);
		SendInventory(peer, inventory);
		stringstream sses;
		sses << "SELECT * FROM PlayerState WHERE username = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
		if (!sses.fail())
		{
			auto basic_string = sses.str();
			auto strings = basic_string.c_str();
			if (mysql_query(conn, strings))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return;
			}
		}
		string name;
		string nick = "";
		string invis = "false";
		string ghost = "false";
		string skin;
		string chatcolor;
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			name = row[1];
			nick = row[2];
			invis = row[3];
			ghost = row[4];
			skin = row[5];
			chatcolor = row[6];
		}
		mysql_free_result(res);

		if (name.length() == 0)
		{
			stringstream ss1;
			ss1 << "INSERT INTO PlayerState(username, nick, invis, ghost, skin, chatcolor) VALUES ('" + static_cast<PlayerInfo*>(peer->data)->rawName + "', '', 'false', 'false', '0x8295C3FF', '')";
			auto query3 = ss1.str();
			auto q2 = query3.c_str();
			if (mysql_query(conn, q2))
			{
						string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return;
			}
		}
		else
		{
			if (skin != "0x8295C3FF") static_cast<PlayerInfo*>(peer->data)->skinColor = atoi(skin.c_str());
			if (isMod(peer) || static_cast<PlayerInfo*>(peer->data)->Subscriber)
			{
				if (nick != "" && isMod(peer))
				{
					static_cast<PlayerInfo*>(peer->data)->isNicked = true;
					if (static_cast<PlayerInfo*>(peer->data)->NickPrefix != "")
					{
						static_cast<PlayerInfo*>(peer->data)->displayName = static_cast<PlayerInfo*>(peer->data)->NickPrefix + ". " + nick;
					}
					else
					{
						static_cast<PlayerInfo*>(peer->data)->displayName = nick;
					}
					static_cast<PlayerInfo*>(peer->data)->OriName = nick;
				}
				if (invis == "true") p->isinv = true;
				if (ghost == "true") p->canWalkInBlocks = true;
				if (chatcolor != "" && static_cast<PlayerInfo*>(peer->data)->Subscriber)
				{
					static_cast<PlayerInfo*>(peer->data)->chatcolor = chatcolor;
				}
			}
		}
		stringstream ssek;
		string named;
		string surgskill;
		ssek << "SELECT * FROM surgery WHERE username = '" + static_cast<PlayerInfo*>(peer->data)->rawName + "'";
		auto querysed = ssek.str();
		auto qlk = querysed.c_str();
		if (mysql_query(conn, qlk))
		{
			string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
			cout << mysql_error(conn) << endl;
			return;
		}
		res = mysql_store_result(conn);
		// ReSharper disable once CppUsingResultOfAssignmentAsCondition
		while (row = mysql_fetch_row(res))
		{
			named = row[1];
			surgskill = row[2];
		}
		mysql_free_result(res);

		if (named.length() > 0)
		{
			static_cast<PlayerInfo*>(peer->data)->SurgerySkill = atoi(surgskill.c_str());
		}
		else
		{
			stringstream ss1;
			ss1 << "INSERT INTO surgery(username, surgeonlevel) VALUES ('" + static_cast<PlayerInfo*>(peer->data)->rawName + "', '0')";
			auto query3 = ss1.str();
			auto q2 = query3.c_str();
			if (mysql_query(conn, q2))
			{
				string ers = mysql_error(conn); if (ers.find("Lost connection") != string::npos) ConnectToDatabase();
				cout << mysql_error(conn) << endl;
				return;
			}
			static_cast<PlayerInfo*>(peer->data)->SurgerySkill = 0;
		}
		auto guildname = PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->guild);
		if (guildname != "")
		{
			try
			{
				std::ifstream ifstream("guilds/" + guildname + ".json");
				if (ifstream.fail())
				{
					ifstream.close();
					SendConsole("Failed to load player guild data! (sendworld) caused by " + static_cast<PlayerInfo*>(peer->data)->rawName, "ERROR");
					static_cast<PlayerInfo*>(peer->data)->guild = "";
				}
				else
				{
					json basic_json;
					ifstream >> basic_json;
					int gfbg, gffg;
					string gstatement, gleader;
					vector<string> gmembers;
					gfbg = basic_json["backgroundflag"];
					gffg = basic_json["foregroundflag"];
					gstatement = basic_json["GuildStatement"].get<std::string>();
					gleader = basic_json["Leader"].get<std::string>();
					for (auto i = 0; i < basic_json["Member"].size(); i++)
					{
						gmembers.push_back(basic_json["Member"][i]);
					}
					static_cast<PlayerInfo*>(peer->data)->guildBg = gfbg;
					static_cast<PlayerInfo*>(peer->data)->guildFg = gffg;
					static_cast<PlayerInfo*>(peer->data)->guildStatement = gstatement;
					static_cast<PlayerInfo*>(peer->data)->guildLeader = gleader;
					static_cast<PlayerInfo*>(peer->data)->guildMembers = gmembers;
				}
				ifstream.close();
			}
			catch (std::exception&)
			{
				SendConsole("Failed to load player guild data! (sendworld) (exception) caused by " + static_cast<PlayerInfo*>(peer->data)->rawName + " guild name " + guildname, "ERROR");
				if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
			}
			catch (std::runtime_error&)
			{
				SendConsole("Failed to load player guild data! (sendworld) (runtime) caused by " + static_cast<PlayerInfo*>(peer->data)->rawName + " guild name " + guildname, "ERROR");
				if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
			}
			catch (...)
			{
				SendConsole("Failed to load player guild data! (sendworld) (...) caused by " + static_cast<PlayerInfo*>(peer->data)->rawName + " guild name " + guildname, "ERROR");
				if (!static_cast<PlayerInfo*>(peer->data)->Console) enet_peer_disconnect_now(peer, 0);
			}
		}

		if (!std::experimental::filesystem::exists("fragments/" + PlayerDB::getProperName(p->rawName) + ".txt"))
		{
			ofstream create("fragments/" + PlayerDB::getProperName(p->rawName) + ".txt");
			create << 0;
			create << 0;
			create << 0;
			create << 0;
			create.close();
		}
		ifstream fd("fragments/" + PlayerDB::getProperName(p->rawName) + ".txt");
		fd >> p->fEarth;
		fd >> p->fDark;
		fd >> p->fFire;
		fd >> p->fWater;
		fd.close();
		if (p->isDuctaped) sendClothes(peer);
		UpdateInventory(peer, static_cast<PlayerInfo*>(peer->data)->rawName);



	}
}

inline void SendRegisterDialog(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId) return;
	static_cast<PlayerInfo*>(peer->data)->Growid = true;
	//Player::OnDialogRequest(peer, "set_default_color|`o\n\nadd_label_with_icon|big|`@Create Your `#Grow-ID`@!``|left|1048|\n\nadd_spacer|small|\nadd_text_input|username|GrowID: ||100|\nadd_text_input|password|Password: ||100|\nadd_text_input|email|Email: ||100|\nend_dialog|register||`2Complete!|\n");
}

inline void FailLogin(ENetPeer* peer, string text, bool withurl)
{
	if (static_cast<PlayerInfo*>(peer->data)->Console)
	{
		Player::OnConsoleMessage(peer, text);
		return;
	}
	if (withurl)
	{
		const string dc = "https://discord.gg/qtSdMWx";
		const auto url = "action|set_url\nurl|" + dc + "\nlabel|Join GTOS Discord\n";
		const auto data = new BYTE[5 + text.length()];
		const auto dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		const auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		delete data;
		delete dataurl;
	}
	else
	{
		const auto data = new BYTE[5 + text.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		delete data;
	}
	static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
}

inline void SendAAPNotification(const string email, const string ip, const string growid)
{
	const auto text = email + " " + ip + " " + growid;
	const auto themessage = "start php aap.php " + text + "";
	const auto c = themessage.c_str();
	system(c);
}

inline string GetItemCount(ENetPeer* peer, int itemid)
{

	/*Surgery Butent Kodas*/
	auto KiekTuri = 0;
	for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
	{
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == itemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
		{
			KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
		}
	}
	if (KiekTuri != 0) return to_string(KiekTuri);
	else return "";

}

inline void UpdateSurgeryItems(ENetPeer* peer)
{


	static_cast<PlayerInfo*>(peer->data)->SurgItem1 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem2 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem3 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem4 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem5 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem6 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem7 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem8 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem9 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem10 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem11 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem12 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem13 = 4320;

	bool iscontains = false;
	vector<int> Tools;
	SearchInventoryItem(peer, 1258, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1258 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Sponge ";

		if (KiekTuri != 0) Tools.push_back(1258);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1260, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1260 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Scalpel ";

		if (KiekTuri != 0) Tools.push_back(1260);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1262, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1262 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Anesthetic ";

		if (KiekTuri != 0) Tools.push_back(1262);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1264, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1264 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Antiseptic ";

		if (KiekTuri != 0) Tools.push_back(1264);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1266, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1266 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Antibiotics ";

		if (KiekTuri != 0 && static_cast<PlayerInfo*>(peer->data)->UnlockedAntibiotic) Tools.push_back(1266);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1268, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1268 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Splint ";

		if (KiekTuri != 0) Tools.push_back(1268);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 1270, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1270 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Stitches ";

		if (KiekTuri != 0) Tools.push_back(1270);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4308, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4308 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Pins ";

		if (KiekTuri != 0) Tools.push_back(4308);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4310, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4310 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Transfusion ";

		if (KiekTuri != 0) Tools.push_back(4310);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4312, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4312 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Defibrillator ";

		if (KiekTuri != 0 && static_cast<PlayerInfo*>(peer->data)->PatientHeartStopped) Tools.push_back(4312);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4314, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4314 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Clamp ";

		if (KiekTuri != 0) Tools.push_back(4314);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4316, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4316 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Ultrasound ";

		if (KiekTuri != 0) Tools.push_back(4316);

	}
	//else Tools.push_back(4320);
	SearchInventoryItem(peer, 4318, 1, iscontains);
	if (iscontains)
	{
		auto KiekTuri = 0;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4318 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
			{
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
			}
		}
		//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Lab Kit";

		if (KiekTuri != 0 && !static_cast<PlayerInfo*>(peer->data)->UnlockedAntibiotic) Tools.push_back(4318);

	}

	if (static_cast<PlayerInfo*>(peer->data)->FixIt) Tools.push_back(1296);

	//else Tools.push_back(4320);

	for (int i = 0; i < Tools.size(); i++)
	{
	
		if (i == 0) static_cast<PlayerInfo*>(peer->data)->SurgItem1 = Tools[i];
		if (i == 1) static_cast<PlayerInfo*>(peer->data)->SurgItem2 = Tools[i];
		if (i == 2) static_cast<PlayerInfo*>(peer->data)->SurgItem3 = Tools[i];

		if (i == 3) static_cast<PlayerInfo*>(peer->data)->SurgItem4 = Tools[i];
		if (i == 4) static_cast<PlayerInfo*>(peer->data)->SurgItem5 = Tools[i];
		if (i == 5) static_cast<PlayerInfo*>(peer->data)->SurgItem6 = Tools[i];

		if (i == 6) static_cast<PlayerInfo*>(peer->data)->SurgItem7 = Tools[i];
		if (i == 7) static_cast<PlayerInfo*>(peer->data)->SurgItem8 = Tools[i];
		if (i == 8) static_cast<PlayerInfo*>(peer->data)->SurgItem9 = Tools[i];

		if (i == 9) static_cast<PlayerInfo*>(peer->data)->SurgItem10 = Tools[i];
		if (i == 10) static_cast<PlayerInfo*>(peer->data)->SurgItem11 = Tools[i];
		if (i == 11) static_cast<PlayerInfo*>(peer->data)->SurgItem12 = Tools[i];

		if (i == 12) static_cast<PlayerInfo*>(peer->data)->SurgItem13 = Tools[i];

	}
	
}

