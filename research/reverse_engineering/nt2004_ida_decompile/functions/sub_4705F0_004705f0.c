_DWORD *__thiscall sub_4705F0(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ebx
  char v4; // cl
  LPVOID *v5; // ebp

  sub_49E090();
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  this[75] = 0;
  *this = &off_5D6A90;
  this[67] = 0;
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  v2 = this[72];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  this[75] = 0;
  this[76] = 0;
  *((_BYTE *)this + 284) = 0;
  *((_BYTE *)this + 285) = 0;
  return this;
}
