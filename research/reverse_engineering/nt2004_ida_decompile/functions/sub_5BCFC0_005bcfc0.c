int __fastcall sub_5BCFC0(int a1, unsigned __int8 *a2, int a3)
{
  int result; // eax
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // ebx
  int v10; // esi
  int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF
  char v13; // [esp+1Ch] [ebp+4h]

  if ( a3 < 1 )
    return 0;
  v13 = *a2;
  v7 = sub_5BD0D0(*a2);
  v8 = v7;
  if ( a3 < v7 )
    return 0;
  if ( ((v13 & 0x40) == 0 || (result = sub_5BD140(a3 - v7)) != 0)
    && (v13 >= 0 || (result = sub_5BD100(&a2[v8], a3 - v8)) != 0) )
  {
    if ( *(_DWORD *)(a2 + 1) == unk_624B10 )
    {
      return -1;
    }
    else
    {
      sub_5BD1D0(a3, &v12, &v11);
      v9 = sub_5BA500(a1, v12, v11);
      if ( sub_5BA600(v9) )
      {
        return -2;
      }
      else
      {
        v10 = sub_5BD220(a2, a3, 1);
        sub_5BD910(a1, v9);
        return v10;
      }
    }
  }
  return result;
}
