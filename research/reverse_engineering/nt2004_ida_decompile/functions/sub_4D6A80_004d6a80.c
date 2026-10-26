int __thiscall sub_4D6A80(void *this)
{
  void *v1; // esi
  int v2; // edi
  int v3; // ebp
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // eax
  CHAR *v7; // eax
  size_t v9; // [esp+10h] [ebp-10h]
  float v10; // [esp+14h] [ebp-Ch] BYREF
  void *v11; // [esp+18h] [ebp-8h]
  _BYTE v12[4]; // [esp+1Ch] [ebp-4h] BYREF

  v1 = this;
  v11 = this;
  sub_4D8430(&v10, v12);
  v2 = 0;
  v9 = 0;
  v3 = 0;
  do
  {
    v4 = sub_4D6DB0(v3, v10);
    if ( v4 )
    {
      sub_51BC20(3, 0);
      sub_4EED10((char *)(v4 + 65));
      sub_50B240((char *)(v4 + 97));
      sub_4EDDD0((char *)(v4 + 1));
      sub_4DEB20(v3 + 1);
      if ( *(_DWORD *)(v4 + 140) )
      {
        v5 = operator new(0x58u);
        if ( v5 )
        {
          *v5 = 0;
          v5[1] = -1;
          v5[2] = 0;
          v5[3] = -1;
          v5[4] = 0;
          v5[5] = -1;
          sub_578600(a100);
          v5[7] = -1;
          v5[6] = 0;
          v5[9] = -1;
          v5[8] = 0;
          sub_414400(v5 + 10);
          sub_414400(v5 + 14);
          sub_414400(v5 + 18);
        }
        else
        {
          v5 = 0;
        }
        sub_509660(*(_DWORD *)(v4 + 140));
        sub_50B320(v5);
        v1 = v11;
      }
      if ( v2 < 1214592 )
        ++v9;
    }
    else
    {
      sub_51BC20(-1, 0);
    }
    v2 += 25304;
    ++v3;
  }
  while ( v2 < 1239896 );
  NumOfElements = v9;
  sub_42DC40();
  v6 = (int)(v9 - 1) < 0 ? 0 : v9 - 1;
  dword_7690A4 = v6;
  if ( v6 >= dword_7690AC )
  {
    if ( v6 > dword_7690B0 )
      dword_7690A4 = dword_7690B0;
  }
  else
  {
    dword_7690A4 = dword_7690AC;
  }
  dword_766E00 = 0;
  if ( dword_766E08 <= 0 )
  {
    if ( dword_766E0C < 0 )
      dword_766E00 = dword_766E0C;
  }
  else
  {
    dword_766E00 = dword_766E08;
  }
  dword_766F44 = 0;
  if ( dword_766F4C <= 0 )
  {
    if ( dword_766F50 < 0 )
      dword_766F44 = dword_766F50;
  }
  else
  {
    dword_766F44 = dword_766F4C;
  }
  dword_767088 = 0;
  if ( dword_767090 <= 0 )
  {
    if ( dword_767094 < 0 )
      dword_767088 = dword_767094;
  }
  else
  {
    dword_767088 = dword_767090;
  }
  v7 = (CHAR *)*((_DWORD *)v1 + 237);
  if ( !v7 )
    v7 = &byte_629120;
  sub_4E8D60(v7);
  sub_4E8A30(&byte_7D6A30);
  byte_75AB9C = 1;
  return sub_42F6C0(&dword_75CBA8, *((_DWORD *)v1 + 511));
}
