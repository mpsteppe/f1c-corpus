// f1c  0x0052da30  size=599
int __thiscall sub_52DA30(int this, unsigned int a2)
{
  unsigned __int8 v3; // dl
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char v9; // [esp+Bh] [ebp-9h]
  bool v10; // [esp+Ch] [ebp-8h]
  unsigned __int8 v11; // [esp+10h] [ebp-4h]
  char v12; // [esp+18h] [ebp+4h]

  if ( (a2 & 0xFFF00000) != 0xFFF00000 )
    return -1;
  v11 = 4 - ((a2 >> 17) & 3);
  v10 = (a2 & 0x200) != 0;
  *(_BYTE *)(this + 9413) = v10;
  *(_BYTE *)(this + 9360) = v11;
  v9 = (a2 >> 6) & 3;
  *(_BYTE *)(this + 9414) = v9;
  *(_BYTE *)(this + 9415) = (a2 >> 4) & 3;
  *(_BYTE *)(this + 9410) = BYTE2(a2) & 1;
  *(_BYTE *)(this + 9416) = (a2 & 8) != 0;
  v3 = (a2 >> 12) & 0xF;
  *(_BYTE *)(this + 9409) = (a2 & 0x80000) != 0;
  *(_BYTE *)(this + 9411) = v3;
  *(_BYTE *)(this + 9417) = (a2 & 4) != 0;
  if ( (a2 & 0x100000) != 0 )
  {
    *(_BYTE *)(this + 9406) = (a2 & 0x80000) == 0;
    *(_BYTE *)(this + 9405) = 0;
  }
  else
  {
    *(_BYTE *)(this + 9406) = 1;
    *(_BYTE *)(this + 9405) = 1;
  }
  if ( *(_BYTE *)(this + 9405) )
  {
    *(_BYTE *)(this + 9412) = ((a2 >> 10) & 3) + 6;
  }
  else
  {
    v12 = (a2 >> 10) & 3;
    *(_BYTE *)(this + 9412) = v12 + 3 * *(_BYTE *)(this + 9406);
    *(_BYTE *)(this + 9407) = v12 + (*(_BYTE *)(this + 9406) != 0 ? 0 : 3);
  }
  v4 = (v9 != 3) + 1;
  v5 = *(unsigned __int8 *)(this + 9412);
  *(_DWORD *)(this + 9420) = v4;
  v6 = dword_5B4764[v5];
  *(_DWORD *)(this + 9424) = 32 * v4;
  *(_DWORD *)(this + 9352) = v6;
  *(_DWORD *)(this + 9348) = v6;
  if ( v3 )
  {
    v7 = word_5B4684[48 * *(unsigned __int8 *)(this + 9406) + 16 * v11 + v3];
    *(_DWORD *)(this + 9364) = v7;
    if ( v11 == 1 )
    {
      *(_DWORD *)(this + 9368) = 4 * (v10 + 12000 * v7 / *(_DWORD *)(this + 9348)) - 4;
      return 0;
    }
    else
    {
      v8 = 144000 * v7 / *(_DWORD *)(this + 9348);
      *(_DWORD *)(this + 9368) = v8;
      if ( v10 )
        *(_DWORD *)(this + 9368) = v8 + 1;
      *(_DWORD *)(this + 9368) -= 4;
      return 0;
    }
  }
  else
  {
    off_5DA714(aAudioAssert);
    off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1310, aCmpegbaseProce);
    off_5DA718();
    return -1;
  }
}
