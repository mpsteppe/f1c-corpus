char __thiscall sub_45C650(unsigned __int8 *this, int a2, _DWORD *a3)
{
  char *v3; // eax
  int v4; // ebx
  int v5; // ebp
  int i; // esi
  int v7; // edi
  char v9; // [esp+13h] [ebp-205h]
  int v10; // [esp+14h] [ebp-204h] BYREF
  char v11[512]; // [esp+18h] [ebp-200h] BYREF

  *a3 = 0;
  v9 = 1;
  if ( (unsigned __int8)sub_568A60(this[1], &v10) )
    *a3 += v10;
  else
    v9 = 0;
  sub_587DD0(v11, a2, 511);
  v11[511] = 0;
  v3 = &v11[strlen(v11)];
  if ( v3 > v11 )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= v11 )
        goto LABEL_9;
    }
    *v3 = 0;
  }
LABEL_9:
  v4 = dword_8AC488;
  v5 = 0;
  if ( dword_8AC488 > 0 )
  {
    for ( i = 0; ; i += 396 )
    {
      v7 = i + dword_8AC490;
      if ( !sub_588410(v11, i + dword_8AC490 + 4) )
        break;
      if ( ++v5 >= v4 )
        return v9;
    }
    *a3 += *(_DWORD *)(v7 + 392);
  }
  return v9;
}
