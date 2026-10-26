int __thiscall sub_5FB020(_DWORD *this, int a2)
{
  _DWORD *v2; // edx
  int result; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // ebp
  _DWORD *i; // edx
  int v8; // edx
  _DWORD *v9; // edx

  if ( a2 != 32 )
    return this[75];
  v2 = (_DWORD *)this[72];
  result = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  this[74] = v2;
  if ( v2 )
  {
    for ( i = (_DWORD *)*v2; i; i = (_DWORD *)*v9 )
    {
      if ( i[2] != v4 || i[3] != v5 || i[5] != v6 )
      {
        v5 = i[3];
        v6 = i[5];
        v4 = i[2];
        ++result;
      }
      v8 = this[74];
      if ( !v8 )
        break;
      v9 = *(_DWORD **)(v8 + 4);
      this[74] = v9;
      if ( !v9 )
        break;
    }
  }
  return result;
}
