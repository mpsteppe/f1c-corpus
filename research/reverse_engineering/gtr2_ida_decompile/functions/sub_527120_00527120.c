char __thiscall sub_527120(int *this, char a2)
{
  int v3; // ecx
  int v4; // edx
  char result; // al
  int v6; // ecx
  int *v7; // edi
  int v8; // eax
  int v9; // ebx
  bool v10; // zf
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // [esp-Ch] [ebp-18h]

  v3 = this[722649];
  v4 = this[722650];
  result = 0;
  if ( v3 < v4 )
  {
    v6 = this[722648] - v4 + v3 + 1;
LABEL_6:
    if ( v6 != 1 || *(_BYTE *)(184 * v4 + this[722647]) )
      goto LABEL_9;
    goto LABEL_8;
  }
  if ( v3 >= 0 && v4 >= 0 )
  {
    v6 = v3 - v4 + 1;
    goto LABEL_6;
  }
LABEL_8:
  v6 = 0;
LABEL_9:
  if ( (v6 == this[722648] || a2) && v6 > 0 )
  {
    v7 = this + 12;
    while ( 1 )
    {
      v8 = *v7;
      v9 = 0;
      v10 = *v7 == 0;
      this[14] = this[12];
      if ( !v10 )
      {
        *(_BYTE *)(v8 + 8) = 0;
        v9 = *(_DWORD *)v8;
        if ( *(_DWORD *)v8 && (v11 = *v7, v12 = 0, *v7) )
        {
          while ( *(_DWORD *)v11 != v9 )
          {
            v12 = v11;
            v11 = *(_DWORD *)(v11 + 4);
            if ( !v11 )
              goto LABEL_18;
          }
          if ( v11 == this[14] )
            this[14] = *(_DWORD *)(v11 + 4);
          if ( v12 )
            *(_DWORD *)(v12 + 4) = *(_DWORD *)(v11 + 4);
          else
            *v7 = *(_DWORD *)(v11 + 4);
          if ( this[13] == v11 )
            this[13] = v12;
          --this[15];
          if ( *(_BYTE *)(v11 + 8) )
            j__free(*(void **)v11);
          j__free((void *)v11);
        }
        else
        {
LABEL_18:
          v9 = 0;
        }
      }
      v13 = v9;
      if ( !v9 )
      {
        sub_525A60();
        v14 = *v7;
        v10 = *v7 == 0;
        this[14] = this[12];
        if ( !v10 )
        {
          v13 = *(_DWORD *)v14;
          v18 = *(_DWORD *)v14;
          *(_BYTE *)(v14 + 8) = 0;
          if ( !(unsigned __int8)sub_524660(this + 12, v18, 1) )
            v13 = 0;
        }
      }
      v15 = sub_525CC0((int *)(this[722647] + 184 * this[722650]), this + 445, (float *)v13);
      if ( v15 <= 0 )
        break;
      v16 = v15 + this[723209];
      ++this[723208];
      this[723209] = v16;
      sub_524350(this + 471, v13, 0);
    }
    *(_DWORD *)v13 = 0;
    *(_DWORD *)(v13 + 4) = 0;
    *(_WORD *)(v13 + 8) = 0;
    sub_5E5780(v13, 0);
    v17 = this[722650];
    if ( v17 != this[722649] )
      this[722650] = (v17 + 1) % this[722648];
    return 1;
  }
  return result;
}
