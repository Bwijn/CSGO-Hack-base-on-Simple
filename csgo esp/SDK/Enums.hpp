#pragma once
//#include"pch.h"

enum ECstrike15UserMessages
{
    CS_UM_VGUIMenu = 1,
    CS_UM_Geiger = 2,
    CS_UM_Train = 3,
    CS_UM_HudText = 4,
    CS_UM_SayText = 5,
    CS_UM_SayText2 = 6,
    CS_UM_TextMsg = 7,
    CS_UM_HudMsg = 8,
    CS_UM_ResetHud = 9,
    CS_UM_GameTitle = 10,
    CS_UM_Shake = 12,
    CS_UM_Fade = 13,
    CS_UM_Rumble = 14,
    CS_UM_CloseCaption = 15,
    CS_UM_CloseCaptionDirect = 16,
    CS_UM_SendAudio = 17,
    CS_UM_RawAudio = 18,
    CS_UM_VoiceMask = 19,
    CS_UM_RequestState = 20,
    CS_UM_Damage = 21,
    CS_UM_RadioText = 22,
    CS_UM_HintText = 23,
    CS_UM_KeyHintText = 24,
    CS_UM_ProcessSpottedEntityUpdate = 25,
    CS_UM_ReloadEffect = 26,
    CS_UM_AdjustMoney = 27,
    CS_UM_UpdateTeamMoney = 28,
    CS_UM_StopSpectatorMode = 29,
    CS_UM_KillCam = 30,
    CS_UM_DesiredTimescale = 31,
    CS_UM_CurrentTimescale = 32,
    CS_UM_AchievementEvent = 33,
    CS_UM_MatchEndConditions = 34,
    CS_UM_DisconnectToLobby = 35,
    CS_UM_PlayerStatsUpdate = 36,
    CS_UM_DisplayInventory = 37,
    CS_UM_WarmupHasEnded = 38,
    CS_UM_ClientInfo = 39,
    CS_UM_XRankGet = 40,
    CS_UM_XRankUpd = 41,
    CS_UM_CallVoteFailed = 45,
    CS_UM_VoteStart = 46,
    CS_UM_VotePass = 47,
    CS_UM_VoteFailed = 48,
    CS_UM_VoteSetup = 49,
    CS_UM_ServerRankRevealAll = 50,
    CS_UM_SendLastKillerDamageToClient = 51,
    CS_UM_ServerRankUpdate = 52,
    CS_UM_ItemPickup = 53,
    CS_UM_ShowMenu = 54,
    CS_UM_BarTime = 55,
    CS_UM_AmmoDenied = 56,
    CS_UM_MarkAchievement = 57,
    CS_UM_MatchStatsUpdate = 58,
    CS_UM_ItemDrop = 59,
    CS_UM_GlowPropTurnOff = 60,
    CS_UM_SendPlayerItemDrops = 61,
    CS_UM_RoundBackupFilenames = 62,
    CS_UM_SendPlayerItemFound = 63,
    CS_UM_ReportHit = 64,
    CS_UM_XpUpdate = 65,
    CS_UM_QuestProgress = 66,
    CS_UM_ScoreLeaderboardData = 67,
    CS_UM_PlayerDecalDigitalSignature = 68,
    MAX_ECSTRIKE15USERMESSAGES
};


enum ItemDefinitionIndex
{
    ITEM_NONE = 0,
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE = 2,
    WEAPON_FIVESEVEN = 3,
    WEAPON_GLOCK = 4,
    WEAPON_AK47 = 7,
    WEAPON_AUG = 8,
    WEAPON_AWP = 9,
    WEAPON_FAMAS = 10,
    WEAPON_G3SG1 = 11,
    WEAPON_GALILAR = 13,
    WEAPON_M249 = 14,
    WEAPON_M4A1 = 16,
    WEAPON_MAC10 = 17,
    WEAPON_P90 = 19,
    WEAPON_UMP45 = 20,
    WEAPON_XM1014 = 21,
    WEAPON_BIZON = 22,
    WEAPON_MAG7 = 23,
    WEAPON_NEGEV = 24,
    WEAPON_SAWEDOFF = 25,
    WEAPON_TEC9 = 26,
    WEAPON_TASER = 27,
    WEAPON_HKP2000 = 28,
    WEAPON_MP7 = 29,
    WEAPON_MP9 = 30,
    WEAPON_NOVA = 31,
    WEAPON_P250 = 32,
    WEAPON_SCAR20 = 33,
    WEAPON_SG556 = 34,
    WEAPON_SSG08 = 35,
    WEAPON_KNIFE = 36,
    WEAPON_FLASHBANG = 37,
    WEAPON_HEGRENADE = 38,
    WEAPON_SMOKEGRENADE = 39,
    WEAPON_MOLOTOV = 40,
    WEAPON_DECOY = 41,
    WEAPON_INCGRENADE = 42,
    WEAPON_C4 = 43,
    WEAPON_KNIFE_T = 44,
    WEAPON_M4A1_SILENCER = 45,
    WEAPON_USP_SILENCER = 46,
    WEAPON_CZ75A = 47,
    WEAPON_REVOLVER = 48,
    WEAPON_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9_BAYONET = 508,
    WEAPON_KNIFE_TACTICAL = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_PUSH = 516,
    GLOVE_STUDDED_BLOODHOUND = 5027,
    GLOVE_T_SIDE = 5028,
    GLOVE_CT_SIDE = 5029,
    GLOVE_SPORTY = 5030,
    GLOVE_SLICK = 5031,
    GLOVE_LEATHER_WRAP = 5032,
    GLOVE_MOTORCYCLE = 5033,
    GLOVE_SPECIALIST = 5034,
    MAX_ITEMDEFINITIONINDEX
};

enum ClassId
{
    ClassId_CAI_BaseNPC = 0,
    ClassId_CAK47,
    ClassId_CBaseAnimating,
    ClassId_CBaseAnimatingOverlay,
    ClassId_CBaseAttributableItem,
    ClassId_CBaseButton,
    ClassId_CBaseCombatCharacter,
    ClassId_CBaseCombatWeapon,
    ClassId_CBaseCSGrenade,
    ClassId_CBaseCSGrenadeProjectile,
    ClassId_CBaseDoor,
    ClassId_CBaseEntity,
    ClassId_CBaseFlex,
    ClassId_CBaseGrenade,
    ClassId_CBaseParticleEntity,
    ClassId_CBasePlayer,
    ClassId_CBasePropDoor,
    ClassId_CBaseTeamObjectiveResource,
    ClassId_CBaseTempEntity,
    ClassId_CBaseToggle,
    ClassId_CBaseTrigger,
    ClassId_CBaseViewModel,
    ClassId_CBaseVPhysicsTrigger,
    ClassId_CBaseWeaponWorldModel,
    ClassId_CBeam,
    ClassId_CBeamSpotlight,
    ClassId_CBoneFollower,
    ClassId_CBreakableProp,
    ClassId_CBreakableSurface,
    ClassId_CC4,
    ClassId_CCascadeLight,
    ClassId_CChicken,
    ClassId_CColorCorrection,
    ClassId_CColorCorrectionVolume,
    ClassId_CCSGameRulesProxy,
    ClassId_CCSPlayer,
    ClassId_CCSPlayerResource,
    ClassId_CCSRagdoll,
    ClassId_CCSTeam,
    ClassId_CDEagle,
    ClassId_CDecoyGrenade,
    ClassId_CDecoyProjectile,
    ClassId_CDynamicLight,
    ClassId_CDynamicProp,
    ClassId_CEconEntity,
    ClassId_CEconWearable,
    ClassId_CEmbers,
    ClassId_CEntityDissolve,
    ClassId_CEntityFlame,
    ClassId_CEntityFreezing,
    ClassId_CEntityParticleTrail,
    ClassId_CEnvAmbientLight,
    ClassId_CEnvDetailController,
    ClassId_CEnvDOFController,
    ClassId_CEnvParticleScript,
    ClassId_CEnvProjectedTexture,
    ClassId_CEnvQuadraticBeam,
    ClassId_CEnvScreenEffect,
    ClassId_CEnvScreenOverlay,
    ClassId_CEnvTonemapController,
    ClassId_CEnvWind,
    ClassId_CFEPlayerDecal,
    ClassId_CFireCrackerBlast,
    ClassId_CFireSmoke,
    ClassId_CFireTrail,
    ClassId_CFish,
    ClassId_CFlashbang,
    ClassId_CFogController,
    ClassId_CFootstepControl,
    ClassId_CFunc_Dust,
    ClassId_CFunc_LOD,
    ClassId_CFuncAreaPortalWindow,
    ClassId_CFuncBrush,
    ClassId_CFuncConveyor,
    ClassId_CFuncLadder,
    ClassId_CFuncMonitor,
    ClassId_CFuncMoveLinear,
    ClassId_CFuncOccluder,
    ClassId_CFuncReflectiveGlass,
    ClassId_CFuncRotating,
    ClassId_CFuncSmokeVolume,
    ClassId_CFuncTrackTrain,
    ClassId_CGameRulesProxy,
    ClassId_CHandleTest,
    ClassId_CHEGrenade,
    ClassId_CHostage,
    ClassId_CHostageCarriableProp,
    ClassId_CIncendiaryGrenade,
    ClassId_CInferno,
    ClassId_CInfoLadderDismount,
    ClassId_CInfoOverlayAccessor,
    ClassId_CItem_Healthshot,
    ClassID_CItemDogTags,
    ClassId_CKnife,
    ClassId_CKnifeGG,
    ClassId_CLightGlow,
    ClassId_CMaterialModifyControl,
    ClassId_CMolotovGrenade,
    ClassId_CMolotovProjectile,
    ClassId_CMovieDisplay,
    ClassId_CParticleFire,
    ClassId_CParticlePerformanceMonitor,
    ClassId_CParticleSystem,
    ClassId_CPhysBox,
    ClassId_CPhysBoxMultiplayer,
    ClassId_CPhysicsProp,
    ClassId_CPhysicsPropMultiplayer,
    ClassId_CPhysMagnet,
    ClassId_CPlantedC4,
    ClassId_CPlasma,
    ClassId_CPlayerResource,
    ClassId_CPointCamera,
    ClassId_CPointCommentaryNode,
    ClassId_CPointWorldText,
    ClassId_CPoseController,
    ClassId_CPostProcessController,
    ClassId_CPrecipitation,
    ClassId_CPrecipitationBlocker,
    ClassId_CPredictedViewModel,
    ClassId_CProp_Hallucination,
    ClassId_CPropDoorRotating,
    ClassId_CPropJeep,
    ClassId_CPropVehicleDriveable,
    ClassId_CRagdollManager,
    ClassId_CRagdollProp,
    ClassId_CRagdollPropAttached,
    ClassId_CRopeKeyframe,
    ClassId_CSCAR17,
    ClassId_CSceneEntity,
    ClassId_CSensorGrenade,
    ClassId_CSensorGrenadeProjectile,
    ClassId_CShadowControl,
    ClassId_CSlideshowDisplay,
    ClassId_CSmokeGrenade,
    ClassId_CSmokeGrenadeProjectile,
    ClassId_CSmokeStack,
    ClassId_CSpatialEntity,
    ClassId_CSpotlightEnd,
    ClassId_CSprite,
    ClassId_CSpriteOriented,
    ClassId_CSpriteTrail,
    ClassId_CStatueProp,
    ClassId_CSteamJet,
    ClassId_CSun,
    ClassId_CSunlightShadowControl,
    ClassId_CTeam,
    ClassId_CTeamplayRoundBasedRulesProxy,
    ClassId_CTEArmorRicochet,
    ClassId_CTEBaseBeam,
    ClassId_CTEBeamEntPoint,
    ClassId_CTEBeamEnts,
    ClassId_CTEBeamFollow,
    ClassId_CTEBeamLaser,
    ClassId_CTEBeamPoints,
    ClassId_CTEBeamRing,
    ClassId_CTEBeamRingPoint,
    ClassId_CTEBeamSpline,
    ClassId_CTEBloodSprite,
    ClassId_CTEBloodStream,
    ClassId_CTEBreakModel,
    ClassId_CTEBSPDecal,
    ClassId_CTEBubbles,
    ClassId_CTEBubbleTrail,
    ClassId_CTEClientProjectile,
    ClassId_CTEDecal,
    ClassId_CTEDust,
    ClassId_CTEDynamicLight,
    ClassId_CTEEffectDispatch,
    ClassId_CTEEnergySplash,
    ClassId_CTEExplosion,
    ClassId_CTEFireBullets,
    ClassId_CTEFizz,
    ClassId_CTEFootprintDecal,
    ClassId_CTEFoundryHelpers,
    ClassId_CTEGaussExplosion,
    ClassId_CTEGlowSprite,
    ClassId_CTEImpact,
    ClassId_CTEKillPlayerAttachments,
    ClassId_CTELargeFunnel,
    ClassId_CTEMetalSparks,
    ClassId_CTEMuzzleFlash,
    ClassId_CTEParticleSystem,
    ClassId_CTEPhysicsProp,
    ClassId_CTEPlantBomb,
    ClassId_CTEPlayerAnimEvent,
    ClassId_CTEPlayerDecal,
    ClassId_CTEProjectedDecal,
    ClassId_CTERadioIcon,
    ClassId_CTEShatterSurface,
    ClassId_CTEShowLine,
    ClassId_CTesla,
    ClassId_CTESmoke,
    ClassId_CTESparks,
    ClassId_CTESprite,
    ClassId_CTESpriteSpray,
    ClassId_CTest_ProxyToggle_Networkable,
    ClassId_CTestTraceline,
    ClassId_CTEWorldDecal,
    ClassId_CTriggerPlayerMovement,
    ClassId_CTriggerSoundOperator,
    ClassId_CVGuiScreen,
    ClassId_CVoteController,
    ClassId_CWaterBullet,
    ClassId_CWaterLODControl,
    ClassId_CWeaponAug,
    ClassId_CWeaponAWP,
    ClassId_CWeaponBaseItem,
    ClassId_CWeaponBizon,
    ClassId_CWeaponCSBase,
    ClassId_CWeaponCSBaseGun,
    ClassId_CWeaponCycler,
    ClassId_CWeaponElite,
    ClassId_CWeaponFamas,
    ClassId_CWeaponFiveSeven,
    ClassId_CWeaponG3SG1,
    ClassId_CWeaponGalil,
    ClassId_CWeaponGalilAR,
    ClassId_CWeaponGlock,
    ClassId_CWeaponHKP2000,
    ClassId_CWeaponM249,
    ClassId_CWeaponM3,
    ClassId_CWeaponM4A1,
    ClassId_CWeaponMAC10,
    ClassId_CWeaponMag7,
    ClassId_CWeaponMP5Navy,
    ClassId_CWeaponMP7,
    ClassId_CWeaponMP9,
    ClassId_CWeaponNegev,
    ClassId_CWeaponNOVA,
    ClassId_CWeaponP228,
    ClassId_CWeaponP250,
    ClassId_CWeaponP90,
    ClassId_CWeaponSawedoff,
    ClassId_CWeaponSCAR20,
    ClassId_CWeaponScout,
    ClassId_CWeaponSG550,
    ClassId_CWeaponSG552,
    ClassId_CWeaponSG556,
    ClassId_CWeaponSSG08,
    ClassId_CWeaponTaser,
    ClassId_CWeaponTec9,
    ClassId_CWeaponTMP,
    ClassId_CWeaponUMP45,
    ClassId_CWeaponUSP,
    ClassId_CWeaponXM1014,
    ClassId_CWorld,
    ClassId_DustTrail,
    ClassId_MovieExplosion,
    ClassId_ParticleSmokeGrenade,
    ClassId_RocketTrail,
    ClassId_SmokeTrail,
    ClassId_SporeExplosion,
    ClassId_SporeTrail,
    MAX_CLASSID
};

enum ECSPlayerBones
{
    PELVIS = 0,
    SPINE_0,
    SPINE_1,
    SPINE_2,
    SPINE_3,
    NECK_0,
    HEAD_0,
    CLAVICLE_L,
    ARM_UPPER_L,
    ARM_LOWER_L,
    HAND_L,
    FINGER_MIDDLE_META_L,
    FINGER_MIDDLE_0_L,
    FINGER_MIDDLE_1_L,
    FINGER_MIDDLE_2_L,
    FINGER_PINKY_META_L,
    FINGER_PINKY_0_L,
    FINGER_PINKY_1_L,
    FINGER_PINKY_2_L,
    FINGER_INDEX_META_L,
    FINGER_INDEX_0_L,
    FINGER_INDEX_1_L,
    FINGER_INDEX_2_L,
    FINGER_THUMB_0_L,
    FINGER_THUMB_1_L,
    FINGER_THUMB_2_L,
    FINGER_RING_META_L,
    FINGER_RING_0_L,
    FINGER_RING_1_L,
    FINGER_RING_2_L,
    WEAPON_HAND_L,
    ARM_LOWER_L_TWIST,
    ARM_LOWER_L_TWIST1,
    ARM_UPPER_L_TWIST,
    ARM_UPPER_L_TWIST1,
    CLAVICLE_R,
    ARM_UPPER_R,
    ARM_LOWER_R,
    HAND_R,
    FINGER_MIDDLE_META_R,
    FINGER_MIDDLE_0_R,
    FINGER_MIDDLE_1_R,
    FINGER_MIDDLE_2_R,
    FINGER_PINKY_META_R,
    FINGER_PINKY_0_R,
    FINGER_PINKY_1_R,
    FINGER_PINKY_2_R,
    FINGER_INDEX_META_R,
    FINGER_INDEX_0_R,
    FINGER_INDEX_1_R,
    FINGER_INDEX_2_R,
    FINGER_THUMB_0_R,
    FINGER_THUMB_1_R,
    FINGER_THUMB_2_R,
    FINGER_RING_META_R,
    FINGER_RING_0_R,
    FINGER_RING_1_R,
    FINGER_RING_2_R,
    WEAPON_HAND_R,
    ARM_LOWER_R_TWIST,
    ARM_LOWER_R_TWIST1,
    ARM_UPPER_R_TWIST,
    ARM_UPPER_R_TWIST1,
    LEG_UPPER_L,
    LEG_LOWER_L,
    ANKLE_L,
    BALL_L,
    LFOOT_LOCK,
    LEG_UPPER_L_TWIST,
    LEG_UPPER_L_TWIST1,
    LEG_UPPER_R,
    LEG_LOWER_R,
    ANKLE_R,
    BALL_R,
    RFOOT_LOCK,
    LEG_UPPER_R_TWIST,
    LEG_UPPER_R_TWIST1,
    FINGER_PINKY_L_END,
    FINGER_PINKY_R_END,
    VALVEBIPED_WEAPON_BONE,
    LH_IK_DRIVER,
    PRIMARY_JIGGLE_JNT,
    MAX_ECSPLAYERBONES
};

enum EntityFlags
{
    FL_ONGROUND = (1 << 0),
    FL_DUCKING = (1 << 1),
    FL_WATERJUMP = (1 << 2),
    FL_ONTRAIN = (1 << 3),
    FL_INRAIN = (1 << 4),
    FL_FROZEN = (1 << 5),
    FL_ATCONTROLS = (1 << 6),
    FL_CLIENT = (1 << 7),
    FL_FAKECLIENT = (1 << 8),
    MAX_ENTITYFLAGS
};


enum PlayerControls_t
{
    IN_ATTACK = (1 << 0),
    IN_JUMP = (1 << 1),
    IN_DUCK = (1 << 2),
    IN_FORWARD = (1 << 3),
    IN_BACK = (1 << 4),
    IN_USE = (1 << 5),
    IN_CANCEL = (1 << 6),
    IN_LEFT = (1 << 7),
    IN_RIGHT = (1 << 8),
    IN_MOVELEFT = (1 << 9),
    IN_MOVERIGHT = (1 << 10),
    IN_ATTACK2 = (1 << 11),
    IN_RUN = (1 << 12),
    IN_RELOAD = (1 << 13),
    IN_ALT1 = (1 << 14),
    IN_ALT2 = (1 << 15),
    IN_SCORE = (1 << 16),
    IN_SPEED = (1 << 17),
    IN_WALK = (1 << 18),
    IN_ZOOM = (1 << 19),
    IN_WEAPON1 = (1 << 20),
    IN_WEAPON2 = (1 << 21),
    IN_BULLRUSH = (1 << 22),
    IN_GRENADE1 = (1 << 23),
    IN_GRENADE2 = (1 << 24),
    IN_ATTACK3 = (1 << 25),
};

enum LifeState : unsigned char
{
    LIFE_ALIVE = 0,// alive
    LIFE_DYING = 1, // playing death animation or still falling off of a ledge waiting to hit ground
    LIFE_DEAD = 2, // dead. lying still.
    MAX_LIFESTATE
};

enum WeaponSound_t
{
    EMPTY,
    SINGLE,
    SINGLE_NPC,
    WPN_DOUBLE, // Can't be "DOUBLE" because windows.h uses it.
    DOUBLE_NPC,
    BURST,
    RELOAD,
    RELOAD_NPC,
    MELEE_MISS,
    MELEE_HIT,
    MELEE_HIT_WORLD,
    SPECIAL1,
    SPECIAL2,
    SPECIAL3,
    TAUNT,
    FAST_RELOAD,
    // Add new shoot sound types here
    REVERSE_THE_NEW_SOUND,
    NUM_SHOOT_SOUND_TYPES,
    MAX_WEAPONSOUND
};

enum MoveType_t
{
    MOVETYPE_NONE = 0,
    MOVETYPE_ISOMETRIC,
    MOVETYPE_WALK,
    MOVETYPE_STEP,
    MOVETYPE_FLY,
    MOVETYPE_FLYGRAVITY,
    MOVETYPE_VPHYSICS,
    MOVETYPE_PUSH,
    MOVETYPE_NOCLIP,
    MOVETYPE_LADDER,
    MOVETYPE_OBSERVER,
    MOVETYPE_CUSTOM,
    MOVETYPE_LAST = MOVETYPE_CUSTOM,
    MOVETYPE_MAX_BITS = 4,
    MAX_MOVETYPE
};
