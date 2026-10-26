int *__thiscall sub_40AF40(_DWORD *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int *result; // eax
  int i; // ecx

  if ( this[18] )
  {
    v2 = 0;
    if ( (int)this[19] > 0 )
    {
      v3 = 0;
      do
      {
        v4 = this[18];
        if ( *(_DWORD *)(v3 + v4) )
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v3 + v4) + 16))(*(_DWORD *)(v3 + v4));
        ++v2;
        v3 += 20;
      }
      while ( v2 < this[19] );
    }
  }
  result = (int *)this[6];
  this[8] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 20))(i);
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
