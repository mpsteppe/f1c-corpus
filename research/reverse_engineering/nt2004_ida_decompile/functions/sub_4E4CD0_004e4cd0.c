int __thiscall sub_4E4CD0(char *this, int a2)
{
  int v3; // ebp
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  int v8; // [esp+10h] [ebp-204h]
  _BYTE v9[512]; // [esp+14h] [ebp-200h] BYREF

  v8 = 0;
  if ( !a2 )
    return 0;
  v3 = sub_4E4C30(this) + 1;
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  do
  {
    if ( v4 )
      v5 = (char *)sub_4E4C60(this, v4 - 1);
    else
      v5 = sub_4E4C50(this);
    v6 = v5;
    if ( v5 )
    {
      sub_4E3D70(v5, v9);
      if ( sub_579060(v9, a2) )
        v8 += *((_DWORD *)v6 + 152);
    }
    ++v4;
  }
  while ( v4 < v3 );
  return v8;
}
