// f1c  0x0049b0a0  size=267
int sub_49B0A0()
{
  const char *v0; // eax
  int result; // eax
  int i; // edi
  char *v3; // esi
  int v4; // eax
  int v5; // ebp
  int v6; // ecx
  void *v7; // esi
  int v8; // [esp+4h] [ebp-204h] BYREF
  _BYTE v9[512]; // [esp+8h] [ebp-200h] BYREF

  v0 = (const char *)dword_5EC3D8;
  v9[0] = 0;
  if ( !dword_5EC3D8 )
    v0 = byte_5EA438;
  sub_58815F(v9, "%s%s", v0, off_5CCB54[0]);
  v8 = 0;
  result = sub_53CBC0(&v8, v9);
  if ( !result )
  {
    for ( i = 0; i < 4; ++i )
    {
      v3 = 0;
      switch ( i )
      {
        case 0:
          v3 = aVehicledisplay;
          break;
        case 1:
          v3 = aNetproblemBmp;
          break;
        case 2:
          v3 = aNexttrackBmp;
          break;
        case 3:
          v3 = aNextsessionBmp;
          break;
        default:
          break;
      }
      v4 = sub_587C03(40);
      v5 = v4;
      if ( v4 )
      {
        sub_4DCB70(v4);
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      dword_7CE23C[i] = v6;
      if ( sub_4DCBA0(-16777216, v3, 0, 0, 0, 32, 32, 0, 0) )
      {
        v7 = (void *)dword_7CE23C[i];
        if ( v7 )
        {
          sub_4DCD10(dword_7CE23C[i]);
          sub_587BCF(v7);
        }
        dword_7CE23C[i] = 0;
      }
    }
    return sub_53CE40(v8);
  }
  return result;
}
