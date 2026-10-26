int *__thiscall sub_40D380(_DWORD *this)
{
  int v2; // ebp
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int *result; // eax
  int i; // ecx
  int v8; // [esp+8h] [ebp-4h]

  v8 = 0;
  if ( (int)this[19] > 0 )
  {
    v2 = 0;
    do
    {
      v3 = this[18];
      v4 = *(_DWORD **)(v3 + v2);
      v5 = v2 + v3;
      if ( v4 )
      {
        if ( v4[5] == 1 || *(_BYTE *)(v5 + 12) )
        {
          sub_40CEE0(v4);
          *(_BYTE *)(this[18] + v2 + 12) = 0;
        }
        else if ( (*(int (__thiscall **)(_DWORD *))(*v4 + 28))(v4) == 2 )
        {
          (*(void (__thiscall **)(_DWORD *))(*v4 + 8))(v4);
        }
      }
      v2 += 20;
      ++v8;
    }
    while ( v8 < this[19] );
  }
  result = (int *)this[6];
  this[8] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 24))(i);
      result = (int *)this[8];
      if ( !result )
        break;
      result = (int *)result[1];
      this[8] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
