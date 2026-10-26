char __thiscall sub_5E9340(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  int *v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // eax
  int *v13; // eax

  if ( !a2 )
    return 0;
  if ( (_BYTE)a3 )
  {
    v4 = (_DWORD *)this[157];
    this[159] = v4;
    if ( v4 )
    {
      if ( *v4 )
      {
        while ( !(unsigned __int8)sub_5E9340(a2, a3) )
        {
          v5 = this[159];
          if ( v5 )
            this[159] = *(_DWORD *)(v5 + 4);
          v6 = (_DWORD *)this[159];
          if ( !v6 || !*v6 )
            goto LABEL_10;
        }
        return 1;
      }
    }
  }
LABEL_10:
  v7 = (int *)this[133];
  this[135] = v7;
  if ( !v7 )
    return 0;
  v8 = *v7;
  if ( !v8 )
    return 0;
  while ( 1 )
  {
    v9 = *(_DWORD *)(v8 + 360);
    v10 = 0;
    if ( v9 > 0 )
      break;
LABEL_16:
    v12 = this[135];
    if ( v12 )
      this[135] = *(_DWORD *)(v12 + 4);
    v13 = (int *)this[135];
    if ( v13 )
    {
      v8 = *v13;
      if ( v8 )
        continue;
    }
    return 0;
  }
  v11 = (_DWORD *)(*(_DWORD *)(v8 + 364) + 4);
  while ( *v11 != a2 )
  {
    ++v10;
    v11 += 27;
    if ( v10 >= v9 )
      goto LABEL_16;
  }
  return 1;
}
