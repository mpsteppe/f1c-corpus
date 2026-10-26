_DWORD *__thiscall sub_4B52A0(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // ebx
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  void *v6; // ebp
  int v7; // eax
  int v8; // ecx

  this[12] = -51331646;
  while ( 1 )
  {
    result = (_DWORD *)this[8];
    this[10] = result;
    if ( !result )
      return result;
    v3 = *result;
    if ( !*result )
      return result;
    v4 = result;
    v5 = 0;
    while ( *v4 != v3 )
    {
      v5 = v4;
      v4 = (_DWORD *)v4[1];
      if ( !v4 )
        goto LABEL_19;
    }
    if ( v4 == (_DWORD *)this[10] )
      this[10] = v4[1];
    if ( v5 )
      v5[1] = v4[1];
    else
      this[8] = v4[1];
    if ( (_DWORD *)this[9] == v4 )
      this[9] = v5;
    --this[11];
    if ( *((_BYTE *)v4 + 8) )
    {
      v6 = (void *)*v4;
      if ( *v4 )
      {
        nullsub_3();
        sub_587BCF(v6);
      }
    }
    sub_587BCF(v4);
LABEL_19:
    v7 = sub_587C03(12);
    if ( v7 )
    {
      *(_DWORD *)v7 = v3;
      *(_DWORD *)(v7 + 4) = 0;
      *(_BYTE *)(v7 + 8) = 0;
    }
    else
    {
      v7 = 0;
    }
    v8 = this[4];
    if ( v8 )
    {
      *(_DWORD *)(v7 + 4) = v8;
    }
    else
    {
      this[5] = v7;
      this[6] = v7;
    }
    this[4] = v7;
    ++this[7];
  }
}
