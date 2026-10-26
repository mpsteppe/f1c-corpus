// f1c  0x00582fd0  size=125
int __thiscall sub_582FD0(_DWORD *this)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  void *v4; // ebp
  int result; // eax

  v2 = (_DWORD *)*this;
  if ( *this )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      if ( *((_BYTE *)v3 + 8) )
      {
        v4 = (void *)*v3;
        if ( *v3 )
        {
          sub_5867B0(*v3);
          sub_587BCF(v4);
        }
      }
      sub_587BCF(v3);
    }
    while ( v2 );
  }
  result = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
