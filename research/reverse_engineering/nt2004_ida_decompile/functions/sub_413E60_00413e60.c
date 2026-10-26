char __thiscall sub_413E60(unsigned __int8 *this, __int16 a2, unsigned __int8 a3)
{
  void *v4; // eax
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  int v7; // ecx

  if ( !a3 )
    return 0;
  *(_WORD *)this = a2;
  this[2] = a3;
  *((_DWORD *)this + 1) = operator new(a3);
  v4 = operator new(this[2]);
  v5 = this[2];
  *((_DWORD *)this + 2) = v4;
  v6 = 0;
  if ( v5 )
  {
    do
    {
      v7 = v6++;
      *(_BYTE *)(v7 + *((_DWORD *)this + 1)) = -1;
      *(_BYTE *)(v7 + *((_DWORD *)this + 2)) = -1;
    }
    while ( v6 < this[2] );
  }
  return 1;
}
