char __thiscall sub_531650(_BYTE *this, int *a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // ebp
  int *v4; // ebp
  char v5; // bl
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v11; // edi
  char *v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // edi
  char *v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // edi
  unsigned int v19; // edi
  char *v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edi
  unsigned int v23; // edi
  char *v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // edi
  __int32 v27[5]; // [esp+0h] [ebp-98h] BYREF
  int v28; // [esp+14h] [ebp-84h] BYREF
  char Buffer[128]; // [esp+18h] [ebp-80h] BYREF

  v4 = a2;
  v5 = 0;
  if ( a2[1] )
  {
    while ( 1 )
    {
      v7 = *v4;
      v27[0] = (__int32)v4;
      v2 = __readeflags();
      v3 = loc_FF8EF4 + dword_16C6D10;
      __writeeflags(v2);
      v4 = (int *)_InterlockedExchange(v27, v3);
      if ( !(*(int (__thiscall **)(int *, char *, __int32))(v7 + 36))(v4, byte_903710, v27[0]) )
        break;
      v5 = 1;
      v8 = sub_612EB0(&unk_9034F8);
      if ( v8 )
      {
        v9 = v8 - 1;
        if ( !v9 || v9 == 3 )
          return v5;
      }
      else if ( sub_6131C0("NAME", (int)Buffer)
             || sub_6131C0("VEHFILE", (int)Buffer)
             || sub_6131C0("RCDFILE", (int)Buffer) )
      {
        sub_615860(Buffer);
      }
      else
      {
        v11 = strlen("FINISHPOSITION");
        v12 = strstr(byte_903710, "FINISHPOSITION");
        if ( v12 )
        {
          v13 = atol(&v12[v11]);
          v14 = v13;
          if ( v13 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", "FINISHPOSITION", v13);
            sub_6133A0(Buffer, (int)&this[4 * v14 + 24], 0, 0, 0);
          }
        }
        v15 = strlen("FINISHPOINTS");
        v16 = strstr(byte_903710, "FINISHPOINTS");
        if ( v16 )
        {
          v17 = atol(&v16[v15]);
          v18 = v17;
          if ( v17 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", "FINISHPOINTS", v17);
            sub_6134B0(Buffer, (int)&this[4 * v18 + 216], 0, 0, 0, 0, 0, 0, 0);
          }
        }
        v19 = strlen("CATEGORYFINISHPOSITION");
        v20 = strstr(byte_903710, "CATEGORYFINISHPOSITION");
        if ( v20 )
        {
          v21 = atol(&v20[v19]);
          v22 = v21;
          if ( v21 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", "CATEGORYFINISHPOSITION", v21);
            sub_6133A0(Buffer, (int)&this[4 * v22 + 408], 0, 0, 0);
          }
        }
        v23 = strlen("CATEGORYFINISHPOINTS");
        v24 = strstr(byte_903710, "CATEGORYFINISHPOINTS");
        if ( v24 )
        {
          v25 = atol(&v24[v23]);
          v26 = v25;
          if ( v25 < 0x30 )
          {
            sprintf(Buffer, "%s%2.2d", "CATEGORYFINISHPOINTS", v25);
            sub_6134B0(Buffer, (int)&this[4 * v26 + 600], 0, 0, 0, 0, 0, 0, 0);
          }
        }
        sub_6134B0("SEASONPOINTS", (int)(this + 792), 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("POINTSPOSITION", (int)(this + 800), 0, 0, 0);
        sub_6134B0("CATEGORYSEASONPOINTS", (int)(this + 796), 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("CATEGORYPOINTSPOSITION", (int)(this + 804), 0, 0, 0);
        sub_6133A0("POLESTAKEN", (int)(this + 808), 0, 0, 0);
        sub_6133A0("ORIGINALGRIDPOSITION", (int)(this + 812), 0, 0, 0);
        sub_6133A0("CURRENTGRIDPOSITION", (int)(this + 816), 0, 0, 0);
        sub_6133A0("TEMPGRIDPOSITION", (int)(this + 820), 0, 0, 0);
        sub_6133A0("WEIGHTPENALTY", (int)(this + 824), 0, 0, 0);
        if ( sub_6133A0("LASTRACEDQ", (int)&v28, 0, 0, 0) )
          this[828] = v28 != 0;
        sub_6133A0("LASTRACELAPSDOWN", (int)(this + 832), 0, 0, 0);
        sub_6133A0("CONTROLTYPE", (int)(this + 836), 0, 0, 0);
        if ( sub_6133A0("ACTIVE", (int)&v28, 0, 0, 0) )
          this[840] = v28 != 0;
      }
    }
  }
  return v5;
}
