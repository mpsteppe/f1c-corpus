void *__thiscall sub_4687D0(LPVOID *this)
{
  char *v2; // esi
  int v3; // edi
  void *result; // eax
  LPVOID **v5; // esi
  LPVOID **v6; // ebp
  char v7; // al
  LPVOID *v8; // edi

  j_nullsub_6(this + 148);
  nullsub_6(this + 126);
  nullsub_6(this + 107);
  if ( this[103] )
    sub_5BE8AE(this[103]);
  v2 = (char *)(this + 100);
  v3 = 48;
  do
  {
    result = (void *)*((_DWORD *)v2 - 2);
    v2 -= 8;
    if ( result )
      result = (void *)sub_5BE8AE(result);
    --v3;
  }
  while ( v3 );
  v5 = (LPVOID **)*this;
  if ( *this )
  {
    do
    {
      v6 = v5;
      v7 = *((_BYTE *)v5 + 8);
      v5 = (LPVOID **)v5[1];
      if ( v7 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          if ( *v8 )
            sub_5BE8AE(*v8);
          sub_5BE8AE(v8);
        }
      }
      result = (void *)sub_5BE8AE(v6);
    }
    while ( v5 );
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
