bool __thiscall sub_42AED0(double *this, const char *a2)
{
  _DWORD *v4; // eax
  bool v5; // zf
  bool v6; // bl
  int v7[15]; // [esp+0h] [ebp-8E8h] BYREF
  _BYTE v8[32]; // [esp+3Ch] [ebp-8ACh] BYREF
  int v9; // [esp+5Ch] [ebp-88Ch]
  _BYTE v10[60]; // [esp+60h] [ebp-888h] BYREF
  char v11[12]; // [esp+A8h] [ebp-840h] BYREF
  char v12[12]; // [esp+B4h] [ebp-834h] BYREF
  char v13[500]; // [esp+C0h] [ebp-828h] BYREF
  char v14[12]; // [esp+2B4h] [ebp-634h] BYREF
  int v15; // [esp+2C0h] [ebp-628h]
  char v16; // [esp+2C4h] [ebp-624h]
  int v17; // [esp+2CCh] [ebp-61Ch]
  int v18; // [esp+2D0h] [ebp-618h]
  int v19; // [esp+2D4h] [ebp-614h]
  char v20[512]; // [esp+2D8h] [ebp-610h] BYREF
  char Buffer[992]; // [esp+4D8h] [ebp-410h] BYREF
  int v22; // [esp+8C0h] [ebp-28h]
  int v23; // [esp+8E4h] [ebp-4h]

  memset(v20, 0, sizeof(v20));
  v15 = 0;
  v19 = 0;
  v17 = 0;
  v18 = 0;
  v16 = 1;
  sub_42AC50();
  sub_613B30(v10);
  v23 = 0;
  if ( (unsigned __int8)sub_614460(a2, 1) )
  {
    v7[5] = 512;
    v7[4] = (int)v20;
    *((_DWORD *)this + 115) = 1;
    *((_DWORD *)this + 112) = 0;
    *((_DWORD *)this + 111) = 0;
    *((_DWORD *)this + 116) = 1;
    v9 = 0;
    if ( sub_613DE0((char *)v7[4], v7[5]) )
    {
      do
      {
        sub_6133A0("SuggestedStats", (int)(this + 58), 0, 0, 0);
        sub_6133A0("Ghostline", (int)this + 460, 0, 0, 0);
        sub_6134B0("GoalXOffset", (int)this + 444, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("GoalYOffset", (int)(this + 56), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("LineTimeTolerance", (int)this + 36, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("StartSpeed", (int)(this + 55), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("GhostRelativeTime", (int)(this + 53), 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MaxGhostCollisionImpulse", (int)this + 452, 0, 0, 0, 0, 0, 0, 0);
        sub_6134B0("MaxTrackCollisionImpulse", (int)(this + 57), 0, 0, 0, 0, 0, 0, 0);
        v7[5] = 0;
        v7[4] = (int)(this + 21);
        v7[3] = (int)"TrackName";
        sub_6137E0(v13);
        if ( sub_6136D0("TiresSurfaceTemp", (int)(this + 54), 0, 0, 0) )
          this[54] = this[54] + 273.16;
        v7[2] = 0;
        v7[1] = (int)(this + 5);
        v7[0] = (int)"VehicleName";
        sub_6137E0(v12);
        sub_6137E0(v11);
        sub_6134B0((char *)off_6F18F0, (int)v7, (int)&v7[1], (int)&v7[2], 0, 0, 0, 0, 0);
        sub_6134B0("Perp", (int)&v7[3], (int)&v7[4], (int)&v7[5], 0, 0, 0, 0, 0);
        sub_6134B0((char *)off_6F18EC, (int)&v7[6], (int)&v7[7], (int)&v7[8], 0, 0, 0, 0, 0);
        sub_6134B0("Time", (int)&v7[13], 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("Gear", (int)&v7[11], 0, 0, 0);
        sub_6134B0("Speed", (int)&v7[12], 0, 0, 0, 0, 0, 0, 0);
        if ( sub_6134B0("Pedals", (int)&v7[9], (int)&v7[10], 0, 0, 0, 0, 0, 0) )
        {
          v4 = operator new(0x3Cu);
          if ( v4 )
            v4[14] = 0;
          else
            v4 = 0;
          qmemcpy(v4, v7, 0x3Cu);
          if ( *(_DWORD *)this )
            *(_DWORD *)(*((_DWORD *)this + 1) + 56) = v4;
          else
            *(_DWORD *)this = v4;
          *((_DWORD *)this + 1) = v4;
        }
      }
      while ( sub_613DE0(v14, 512) );
    }
    sub_613C30(v8);
    v5 = *(_DWORD *)this == 0;
    *((_DWORD *)this + 2) = *(_DWORD *)this;
    v6 = !v5;
    v22 = -1;
    sub_614140(v8);
    return v6;
  }
  else
  {
    sprintf(Buffer, "Driving school: can't find this file! (%s)", a2);
    sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
    v23 = -1;
    sub_614140(v10);
    return 0;
  }
}
