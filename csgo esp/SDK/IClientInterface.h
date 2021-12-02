#include"pch.h"
#pragma once

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);//  每个dll的导出接口  用于和clientengine 交互
class IBaseClientDLL
{
public:
    virtual int              Connect(CreateInterfaceFn appSystemFactory, void* pGlobals) = 0;
    virtual int              Disconnect(void) = 0;
    virtual int              Init(CreateInterfaceFn appSystemFactory, void* pGlobals) = 0;
    virtual void             PostInit() = 0;
    virtual void             Shutdown(void) = 0;
    virtual void             LevelInitPreEntity(char const* pMapName) = 0;
    virtual void             LevelInitPostEntity() = 0;
    virtual void             LevelShutdown(void) = 0;
    virtual void* GetAllClasses(void) = 0;
};
#define CLIENT_DLL_INTERFACE_VERSION		"VClient018"

class CHLClient : public IBaseClientDLL
{
public:
    CHLClient();

    virtual int                        Init(void* appSystemFactory, void* physicsFactory, void* pGlobals);

    virtual void                    PostInit();
    virtual void                    Shutdown(void);

    virtual bool                    ReplayInit(void* fnReplayFactory);
    virtual bool                    ReplayPostInit();

    virtual void                    LevelInitPreEntity(const char* pMapName);
    virtual void                    LevelInitPostEntity();
    virtual void                    LevelShutdown(void);

    virtual void* GetAllClasses(void);

    virtual int                        HudVidInit(void);
    virtual void                    HudProcessInput(bool bActive);
    virtual void                    HudUpdate(bool bActive);
    virtual void                    HudReset(void);
    virtual void                    HudText(const char* message);

    // Mouse Input Interfaces
    virtual void                    IN_ActivateMouse(void);
    virtual void                    IN_DeactivateMouse(void);
    virtual void                    IN_Accumulate(void);
    virtual void                    IN_ClearStates(void);
    virtual bool                    IN_IsKeyDown(const char* name, bool& isdown);
    virtual void                    IN_OnMouseWheeled(int nDelta);
    // Raw signal
    virtual int                        IN_KeyEvent(int eventcode, void* keynum, const char* pszCurrentBinding);
    virtual void                    IN_SetSampleTime(float frametime);
    // Create movement command
    virtual void                    CreateMove(int sequence_number, float input_sample_frametime, bool active);
    virtual void                    ExtraMouseSample(float frametime, bool active);
    virtual bool                    WriteUsercmdDeltaToBuffer(void* buf, int from, int to, bool isnewcommand);
    virtual void                    EncodeUserCmdToBuffer(void* buf, int slot);
    virtual void                    DecodeUserCmdFromBuffer(void* buf, int slot);


    virtual void                    View_Render(void* rect);
    virtual void                    RenderView(const void* view, int nClearFlags, int whatToDraw);
    virtual void                    View_Fade(void* pSF);

    virtual void                    SetCrosshairAngle(const int& angle);// QAngle&

    virtual void                    InitSprite(void* pSprite, const char* loadname);
    virtual void                    ShutdownSprite(void* pSprite);

    virtual int                        GetSpriteSize(void) const;

    virtual void                    VoiceStatus(int entindex, void* bTalking);

    virtual void                    InstallStringTableCallback(const char* tableName);

    virtual void                    FrameStageNotify(void* curStage);

    virtual bool                    DispatchUserMessage(int msg_type, void* msg_data);

    // Save/restore system hooks
    virtual void* SaveInit(int size);
    virtual void            SaveWriteFields(void*, const char*, void*, void*, void*, int);
    virtual void            SaveReadFields(void*, const char*, void*, void*, void*, int);
    virtual void            PreSave(void*);
    virtual void            Save(void*);
    virtual void            WriteSaveHeaders(void*);
    virtual void            ReadRestoreHeaders(void*);
    virtual void            Restore(void*, bool);
    virtual void            DispatchOnRestore();
    virtual void            WriteSaveGameScreenshot(const char* pFilename);

    // Given a list of "S(wavname) S(wavname2)" tokens, look up the localized text and emit
    //  the appropriate close caption if running with closecaption = 1
    virtual void            EmitSentenceCloseCaption(char const* tokenstream);
    virtual void            EmitCloseCaption(char const* captionname, float duration);

    virtual void* GetStandardRecvProxies();

    virtual bool            CanRecordDemo(char* errorMsg, int length) const;

    virtual void            OnDemoRecordStart(char const* pDemoBaseName);
    virtual void            OnDemoRecordStop();
    virtual void            OnDemoPlaybackStart(char const* pDemoBaseName);
    virtual void            OnDemoPlaybackStop();

    virtual bool            ShouldDrawDropdownConsole();

    // Get client screen dimensions
    virtual int                GetScreenWidth();
    virtual int                GetScreenHeight();

    // save game screenshot writing
    virtual void            WriteSaveGameScreenshotOfSize(const char* pFilename, int width, int height, bool bCreatePowerOf2Padded/*=false*/, bool bWriteVTF/*=false*/);

    // Gets the location of the player viewpoint
    virtual bool            GetPlayerView(void* playerView);

    // Matchmaking
    virtual void            SetupGameProperties(void* contexts, void* properties);
    virtual void* GetPresenceID(const char* pIDName);
    virtual const char* GetPropertyIdString(const void* id);
    virtual void            GetPropertyDisplayString(void* id, void* value, char* pOutput, int nBytes);
    virtual void            StartStatsReporting(HANDLE handle, bool bArbitrated);

    virtual void            InvalidateMdlCache();

    virtual void            ReloadFilesInList(void* pFilesToReload);

    // Let the client handle UI toggle - if this function returns false, the UI will toggle, otherwise it will not.
    virtual bool            HandleUiToggle();

    // Allow the console to be shown?
    virtual bool            ShouldAllowConsole();

    // Get renamed recv tables
    virtual void* GetRenamedRecvTableInfos();

    // Get the mouthinfo for the sound being played inside UI panels
    virtual void* GetClientUIMouthInfo();

    // Notify the client that a file has been received from the game server
    virtual void            FileReceived(const char* fileName, unsigned int transferID);

    virtual const char* TranslateEffectForVisionFilter(const char* pchEffectType, const char* pchEffectName);

    virtual void            ClientAdjustStartSoundParams(struct StartSoundParams_t& params);

    // Returns true if the disconnect command has been handled by the client
    virtual bool DisconnectAttempt(void);
public:
    void PrecacheMaterial(const char* pMaterialName);

    virtual bool IsConnectedUserInfoChangeAllowed(void* pCvar);

private:
    void UncacheAllMaterials();
    void ResetStringTablePointers();

    void* m_CachedMaterials;
};

class ClientModeShared
{
//public:
//    bool IsChatPanelOutOfFocus(void)
//    {
//        typedef PVOID(__thiscall* OriginalFn)(PVOID);
//        PVOID CHudChat = get_vfunc<OriginalFn>(this, 19)(this);
//        if (CHudChat)
//        {
//            return *(PFLOAT)((DWORD)CHudChat + 0xFC) == 0;
//        }
//        return false;
//    }
};


//-----------------------------------------------------------------------------
// Purpose: Exposes IClientEntity's to engine
//-----------------------------------------------------------------------------
class IClientEntityList
{
public:
    // Get IClientNetworkable interface for specified entity
    virtual void* GetClientNetworkable(int entnum) = 0;
    virtual void* GetClientNetworkableFromHandle(int hEnt) = 0;
    virtual void* GetClientUnknownFromHandle(int hEnt) = 0;

    // NOTE: This function is only a convenience wrapper.
    // It returns GetClientNetworkable( entnum )->GetIClientEntity().
    virtual void* GetClientEntity(int entnum) = 0; //  add each piece as needed and slowly build your own SDK. so void* instead  
    virtual void* GetClientEntityFromHandle(int hEnt) = 0;

    // Returns number of entities currently in use
    virtual int					NumberOfEntities(bool bIncludeNonNetworkable) = 0;

    // Returns highest index actually used
    virtual int					GetHighestEntityIndex(void) = 0;

    // Sizes entity list to specified size
    virtual void				SetMaxEntities(int maxents) = 0;
    virtual int					GetMaxEntities() = 0;
};



class IClientMode
{
public:
    virtual             ~IClientMode() {}
    virtual int         ClientModeCSNormal(void*) = 0;
    virtual void        Init() = 0;
    virtual void        InitViewport() = 0;
    virtual void        Shutdown() = 0;
    virtual void        Enable() = 0;
    virtual void        Disable() = 0;
    virtual void        Layout() = 0;
    virtual void* GetViewport() = 0;
    virtual void* GetViewportAnimationController() = 0;
    virtual void        ProcessInput(bool bActive) = 0;
    virtual bool        ShouldDrawDetailObjects() = 0;
    virtual bool        ShouldDrawEntity(void* pEnt) = 0;
    virtual bool        ShouldDrawLocalPlayer(void* pPlayer) = 0;
    virtual bool        ShouldDrawParticles() = 0;
    virtual bool        ShouldDrawFog(void) = 0;
    virtual void        OverrideView(void* pSetup) = 0;
    virtual int         KeyInput(int down, int keynum, const char* pszCurrentBinding) = 0;
    virtual void        StartMessageMode(int iMessageModeType) = 0;
    virtual void* GetMessagePanel() = 0;
    virtual void        OverrideMouseInput(float* x, float* y) = 0;
    virtual bool        CreateMove(float flInputSampleTime, void* usercmd) = 0;
    virtual void        LevelInit(const char* newmap) = 0;
    virtual void        LevelShutdown(void) = 0;
};


//
//class IBaseClientDLL
//{
//public:
//    virtual int              Connect(CreateInterfaceFn appSystemFactory, void* pGlobals) = 0;
//    virtual int              Disconnect(void) = 0;
//    virtual int              Init(CreateInterfaceFn appSystemFactory, void* pGlobals) = 0;
//    virtual void             PostInit() = 0;
//    virtual void             Shutdown(void) = 0;
//    virtual void             LevelInitPreEntity(char const* pMapName) = 0;
//    virtual void             LevelInitPostEntity() = 0;
//    virtual void             LevelShutdown(void) = 0;
//    virtual void* GetAllClasses(void) = 0;
//};


//#define CLIENT_DLL_INTERFACE_VERSION		"VClient018"
//#define VCLIENTENTITYLIST_INTERFACE_VERSIO
