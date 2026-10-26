int __thiscall sub_502130(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  int v4; // esi
  _DWORD *v5; // edi
  int v6; // esi
  _DWORD *v7; // edi
  int v9; // [esp+Ch] [ebp-4h]

  v9 = *(_DWORD *)dword_7689CC;
  v2 = 0;
  v3 = this + 9;
  do
  {
    if ( (unsigned __int8)sub_502980(v2, v9) )
      *v3 = sub_503DE0(v2);
    ++v2;
    ++v3;
  }
  while ( v2 < 5 );
  v4 = 0;
  v5 = this + 14;
  do
    *v5++ = sub_504390(v4++);
  while ( v4 < 3 );
  v6 = 0;
  v7 = this + 7;
  do
  {
    if ( (unsigned __int8)sub_5029C0(v6, v9) )
      *v7 = sub_505640(v6);
    ++v6;
    ++v7;
  }
  while ( v6 < 2 );
  this[17] = sub_505790();
  return 0;
}
