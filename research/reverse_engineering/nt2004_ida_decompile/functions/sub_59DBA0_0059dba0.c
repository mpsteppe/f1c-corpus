int __thiscall sub_59DBA0(void *this, FILE *Stream, int a3, int *a4, size_t ElementCount, int a6)
{
  int v6; // edx
  int v7; // eax
  char v8; // cl
  int v9; // eax
  unsigned int v10; // esi
  int v12; // edx
  int v13; // ebp
  int v14; // ebx
  int v15; // eax
  int v16; // edi
  _DWORD *v17; // eax
  _DWORD *v18; // edi
  unsigned int v19; // esi
  char *v20; // eax
  _DWORD *i; // esi
  char v23[16]; // [esp+14h] [ebp-10h] BYREF
  size_t ElementCounta; // [esp+34h] [ebp+10h]

  if ( ElementCount )
  {
    v6 = *(_DWORD *)(ElementCount + 296);
    v7 = *(_DWORD *)(ElementCount + 292) << 8;
    v8 = *(_BYTE *)(v7 + v6);
    v9 = v6 + v7;
    if ( (v8 & 0x10) != 0 )
    {
      v10 = *(_DWORD *)(v9 + 12);
      dword_7F5E68 = (int)operator new(*(_DWORD *)(v9 + 8));
      dword_7F5E6C = (int)operator new(v10);
      if ( sub_5BED6F((void *)dword_7F5E6C, 1u, v10, Stream) != v10 )
      {
        sub_5BE8AE();
        dword_7F5E68 = 0;
        sub_5BE8AE();
        dword_7F5E6C = 0;
        return -1;
      }
      sub_5D2750(dword_7F5E6C, v10);
      goto LABEL_6;
    }
    dword_7F5E6C = 0;
    ElementCounta = *(_DWORD *)(v9 + 8);
    dword_7F5E68 = (int)operator new(ElementCounta);
    v15 = sub_5BED6F((void *)dword_7F5E68, 1u, ElementCounta, Stream);
  }
  else
  {
    v16 = ftell(Stream);
    fseek(Stream, 0, 2);
    ElementCounta = ftell(Stream) - v16;
    fseek(Stream, v16, 0);
    dword_7F5E6C = 0;
    dword_7F5E68 = (int)operator new(ElementCounta);
    v15 = sub_5BED6F((void *)dword_7F5E68, 1u, ElementCounta, Stream);
  }
  if ( v15 != ElementCounta )
  {
    sub_5BE8AE();
    dword_7F5E68 = 0;
    return -1;
  }
LABEL_6:
  dword_7F5E74 = 0;
  sub_59D490(v23, dword_7F5E68, 0x10u);
  v13 = sub_59D480();
  v14 = 420;
  if ( !strcmp(v23, aCubeMts420) )
    goto LABEL_18;
  if ( !strcmp(v23, aCubeMts410) )
  {
    v14 = 410;
LABEL_18:
    v17 = operator new(0x34u);
    if ( v17 )
      v18 = sub_5997B0(v17);
    else
      v18 = 0;
    if ( sub_599F40(v18, (int)this, v14) )
    {
      if ( v18 )
      {
        j_nullsub_6(v18);
        sub_5BE8AE();
      }
      sub_591C60((int)this, -1, aErrorAllocatin);
      return -1;
    }
    else
    {
      sub_59D450(dword_7F5E68, v13, 0);
      if ( sub_599F40(*(_DWORD **)(dword_7E8E5C + 276), (int)this, v14) )
      {
        sub_591C60((int)this, -1, aErrorReadingSc);
        return -1;
      }
      else
      {
        v19 = a3 - sub_59D480();
        v20 = (char *)operator new(v19);
        *a4 = (int)v20;
        sub_59AC90(v20, 0);
        if ( sub_59D490((void *)*a4, dword_7F5E68, v19) == v19 )
        {
          if ( sub_59AE80(*a4, v18, 0) )
          {
            return -1;
          }
          else
          {
            sub_59DFD0(64, 32, 0);
            for ( i = (_DWORD *)v18[9]; i; i = (_DWORD *)i[42] )
              sub_599B10(v18, i);
            sub_599800(v18);
            j_nullsub_6(v18);
            sub_5BE8AE();
            if ( dword_7F5E68 )
              sub_5BE8AE();
            if ( dword_7F5E6C )
              sub_5BE8AE();
            dword_7F5E68 = 0;
            dword_7F5E6C = 0;
            return 0;
          }
        }
        else
        {
          if ( *a4 )
          {
            j_nullsub_6((void *)*a4);
            sub_5BE8AE();
          }
          sub_591C60((int)this, -1, aErrorReadingMe);
          return -1;
        }
      }
    }
  }
  if ( v12 )
    sub_5BE8AE();
  if ( dword_7F5E6C )
    sub_5BE8AE();
  dword_7F5E68 = 0;
  dword_7F5E6C = 0;
  sub_591C60((int)this, -1, aWrongMtsVersio);
  return -1;
}
