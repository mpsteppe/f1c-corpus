int __thiscall sub_460E90(int this)
{
  int v2; // edi
  LPVOID *v3; // eax
  LPVOID *v4; // edi
  char *v5; // eax
  int result; // eax
  int v7; // eax
  float v8; // [esp+0h] [ebp-200h]
  _BYTE v9[64]; // [esp+10h] [ebp-1F0h] BYREF
  _DWORD v10[108]; // [esp+50h] [ebp-1B0h] BYREF

  v8 = dbl_8AFEA0;
  sub_4B33B0(4, 38, 0, 255, LODWORD(v8), 1);
  v2 = sub_57A680(*(_DWORD *)(this + 16312));
  *(_BYTE *)(v2 + 4) = 1;
  sub_57A6A0(v10, ((v10[0] >> 8) & 0x3FF) + 8, v2, 1, 1, -1, 0);
  sub_57A690(*(_DWORD *)(this + 16312), v2);
  *(_BYTE *)(this + 41) = 1;
  v3 = (LPVOID *)sub_587C03(8);
  if ( v3 )
  {
    *v3 = 0;
    v3[1] = (LPVOID)-1;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  sub_566650(aOpening);
  sub_4C5920(v9, 63);
  sub_5665B0(v9);
  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4833) )
  {
    v5 = (char *)*v4;
    if ( !*v4 )
      v5 = byte_5EA438;
    sub_4D7AA0(&unk_8AD25C, v5);
  }
  result = dword_7D0398;
  if ( dword_7D0398 )
  {
    if ( v4 )
    {
      v7 = sub_587C03(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = v4;
        *(_DWORD *)(v7 + 4) = 0;
        *(_BYTE *)(v7 + 8) = 0;
      }
      else
      {
        v7 = 0;
      }
      if ( *(_DWORD *)(this + 112496) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 112500) + 4) = v7;
      }
      else
      {
        *(_DWORD *)(this + 112496) = v7;
        *(_DWORD *)(this + 112504) = v7;
      }
      *(_DWORD *)(this + 112500) = v7;
      result = *(_DWORD *)(this + 112508) + 1;
      *(_DWORD *)(this + 112508) = result;
    }
  }
  else if ( v4 )
  {
    if ( *v4 )
      sub_587BCF(*v4);
    return sub_587BCF(v4);
  }
  return result;
}
