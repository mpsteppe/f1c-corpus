char __userpurge sub_5352C0@<al>(int a1@<esi>, _DWORD *a2)
{
  void **v2; // eax
  void **v3; // esi
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-110h]
  int v8[66]; // [esp+4h] [ebp-108h] BYREF

  if ( a2[1] )
  {
    v7 = a1;
    v2 = (void **)operator new(0x24u);
    if ( v2 )
    {
      *v2 = 0;
      v2[1] = (void *)-1;
      v2[2] = 0;
      v2[3] = (void *)-1;
      v2[4] = 0;
      v2[5] = (void *)-1;
      v2[7] = 0;
      v2[8] = 0;
      v2[6] = (void *)3;
      v3 = v2;
    }
    else
    {
      v3 = 0;
    }
    while ( (*(int (__thiscall **)(_DWORD *, char *, int, int))(*a2 + 36))(a2, byte_903710, 256, v7) )
    {
      v4 = sub_612EB0(&unk_9034F8);
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( !v5 || v5 == 3 )
          break;
      }
      else
      {
        if ( strstr(byte_903710, "[PLAYERTRACKSTAT]") )
          sub_5352C0(a2);
        sub_6133A0("TotalNumLaps", (int)(v3 + 7), 0, 0, 0);
        sub_6134B0("BestLapTime", (int)(v3 + 8), 0, 0, 0, 0, 0, 0, 0);
        sub_6133A0("Mode", (int)(v3 + 6), 0, 0, 0);
        if ( sub_6131C0("Trackname", (int)v8) )
          sub_615860(v8);
        if ( sub_6131C0("TrackFile", (int)v8) )
          sub_615860(v8);
        if ( sub_6131C0("CarDescription", (int)v8) )
          sub_615860(v8);
      }
    }
    if ( !sub_533890() )
    {
      sub_5FDFB0(v3, 1);
      return 0;
    }
    if ( v3[4] )
      j_j__free(v3[4]);
    if ( v3[2] )
      j_j__free(v3[2]);
    if ( *v3 )
      j_j__free(*v3);
    j__free(v3);
  }
  return 0;
}
