int __thiscall sub_4C78F0(int this, int a2)
{
  const char **v2; // esi
  int v4; // eax
  int v5; // eax
  int result; // eax
  const char *v7; // ecx

  v2 = (const char **)(dword_8AC394 + 1060 * a2);
  SetDriverName((char *)this, (int)(v2 + 47));
  sub_587DD0(this + 18016, byte_5EA438, 23);
  *(_BYTE *)(this + 18039) = 0;
  if ( AudioChannelStop(this + 17952) )
  {
    v4 = StringKeyedLinkedListSearch(aNationality);
    if ( v4 )
    {
      v5 = DataEntryAccessor(v4);
      sub_587DD0(this + 18016, v5, 23);
      *(_BYTE *)(this + 18039) = 0;
    }
  }
  sub_587DD0(this + 18040, v2 + 63, 63);
  *(_BYTE *)(this + 18103) = 0;
  sub_587DD0(this + 18104, v2 + 31, 63);
  *(_BYTE *)(this + 18167) = 0;
  result = ShortStringSet((_DWORD *)this, (int)(v2 + 29));
  v7 = *v2;
  if ( !*v2 )
    v7 = byte_5EA438;
  strcpy((char *)(this + 18196), v7);
  *(_DWORD *)(this + 18584) = a2;
  return result;
}
