// f1c  0x004d1030  size=165
int __thiscall sub_4D1030(void *this)
{
  int v1; // edi
  _DWORD *v3; // esi
  int v4; // edi
  char *v5; // esi
  _BYTE v7[12]; // [esp+10h] [ebp-80h] BYREF
  _BYTE v8[116]; // [esp+1Ch] [ebp-74h] BYREF

  v1 = 0;
  v3 = &unk_5F0F80;
  do
  {
    if ( *(v3 - 1400) != -1 )
    {
      v8[v1 + 12] = sub_4EFFD0(v3 - 4647);
      *(v3 - 1) = -1;
      *v3 = -1;
    }
    v3 += 4656;
    ++v1;
  }
  while ( (int)v3 < (int)dword_7C9D80 );
  v4 = 0;
  v5 = (char *)&unk_5EC6D8;
  do
  {
    if ( *((_DWORD *)v5 + 3250) != -1 )
    {
      sub_4D1140(v5, v8, v7);
      if ( v8[v4 + 12] )
        sub_4EF7C0(v8, v7);
    }
    v5 += 18624;
    ++v4;
  }
  while ( (int)v5 < (int)byte_7C54D8 );
  return sub_4D1670(this);
}
