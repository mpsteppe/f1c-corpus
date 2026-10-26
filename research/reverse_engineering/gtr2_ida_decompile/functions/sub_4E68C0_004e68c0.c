int __stdcall sub_4E68C0(int a1)
{
  const char *v1; // eax
  int result; // eax
  int i; // edi
  const char *v4; // esi
  void *v5; // eax
  void *v6; // ebp
  void *v7; // ecx
  void *v8; // esi
  void *Block[2]; // [esp+24h] [ebp-214h] BYREF
  char Buffer[512]; // [esp+2Ch] [ebp-20Ch] BYREF
  int v11; // [esp+234h] [ebp-4h]

  v1 = *(const char **)dword_91CA70;
  Buffer[0] = 0;
  if ( !*(_DWORD *)dword_91CA70 )
    v1 = WindowName;
  sprintf(Buffer, "%s%s", v1, off_75B188[0]);
  Block[0] = 0;
  result = sub_5EE940((int)Block, (char)Buffer, 0);
  if ( !result )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( a1 >= 0 )
        i = a1;
      v4 = 0;
      switch ( i )
      {
        case 0:
          v4 = "VehicleDisplay.bmp";
          break;
        case 1:
          v4 = "NetProblem.bmp";
          break;
        case 2:
          v4 = "NextTrack.bmp";
          break;
        case 3:
          v4 = "NextSession.bmp";
          break;
        default:
          break;
      }
      if ( !*(&dword_B6E4C0 + i) )
      {
        v5 = operator new(0x28u);
        v6 = v5;
        Block[1] = v5;
        v11 = 0;
        if ( v5 )
        {
          sub_567CD0(v5);
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        v11 = -1;
        *(&dword_B6E4C0 + i) = v7;
        if ( sub_568550(-16777216, v4, 0, 0, 0, 32, 32, 0, 0) )
        {
          v8 = *(&dword_B6E4C0 + i);
          if ( v8 )
          {
            sub_567D00(*(&dword_B6E4C0 + i));
            j__free(v8);
          }
          *(&dword_B6E4C0 + i) = 0;
        }
      }
      if ( a1 >= 0 )
        break;
    }
    return sub_5EEA30(dword_FB1CE0, Block[0], 0);
  }
  return result;
}
