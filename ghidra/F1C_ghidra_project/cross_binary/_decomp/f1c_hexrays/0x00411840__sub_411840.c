// f1c  0x00411840  size=355
int __stdcall sub_411840(_DWORD *a1, int a2)
{
  int v3; // ebx
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  int v8; // [esp+10h] [ebp-4h]
  int v9; // [esp+18h] [ebp+4h]
  int v10; // [esp+1Ch] [ebp+8h]

  v3 = 0;
  v4 = sub_4119D0(*a1);
  v5 = v4;
  if ( v4 == -1 )
    return v3;
  v9 = sub_411A00(*a1, v4);
  v6 = sub_411A50(*a1);
  v8 = v6;
  if ( v9 < 0 || v6 < 0 )
    return v3;
  if ( (byte_5EA5E0 & 1) == 0 )
  {
    byte_5EA5E0 |= 1u;
    dword_5EA5D0 = 0;
    dword_5EA5D4 = -1;
    sub_566650(&byte_5EA438);
    dword_5EA5D8 = -1;
    dword_5EA5DC = -1;
    sub_587B3E(sub_4119B0);
  }
  sub_566650(&byte_5EA438);
  dword_5EA5D8 = -1;
  dword_5EA5DC = -1;
  if ( sub_411B50(v9 + v8, v5, &dword_5EA5D0, *a1) )
    return v3;
  if ( sub_411BF0(v5, &dword_5EA5D0, a1, a2) == 1 )
  {
    sub_414140(a2);
    v3 = 1;
  }
  if ( sub_411DB0(v5, &dword_5EA5D0, a1, a2 + 20 * v3, *a1) == 1 )
  {
    ++v3;
    v10 = a2 + 20 * v3;
    if ( sub_411E90(v5, &dword_5EA5D0, a1, v10) == 1 )
    {
      sub_414140(v10);
      ++v3;
    }
    return v3;
  }
  return 0;
}
