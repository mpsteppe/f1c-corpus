_DWORD *__thiscall sub_4B71E0(int this)
{
  int v1; // ebx
  _DWORD *result; // eax
  int v3; // esi
  _DWORD *v4; // ebp
  _DWORD *v5; // edi
  int v7; // edi
  LPVOID **v8; // ebx
  char v9; // al
  LPVOID *v10; // ebp

  sub_4B5F60((_DWORD *)this);
  sub_4B5E50((_DWORD *)this);
  v7 = *(_DWORD *)(this + 1728);
  while ( v7 )
  {
    v8 = (LPVOID **)v7;
    v9 = *(_BYTE *)(v7 + 12);
    v7 = *(_DWORD *)(v7 + 4);
    if ( v9 )
    {
      v10 = *v8;
      if ( *v8 )
      {
        if ( v10[1] )
          sub_587BCF(v10[1]);
        sub_587BCF(v10);
      }
    }
    sub_587BCF(v8);
  }
  *(_DWORD *)(this + 1728) = 0;
  *(_DWORD *)(this + 1732) = 0;
  *(_DWORD *)(this + 1736) = 0;
  *(_DWORD *)(this + 1740) = 0;
  sub_4B52A0((_DWORD *)(this + 3908));
  *(_DWORD *)(this + 3896) = 0;
  *(_DWORD *)(this + 3900) = 0;
  *(_BYTE *)(this + 1744) = 0;
  *(_DWORD *)(this + 2488) = -1;
  *(_DWORD *)(this + 2492) = -1;
  *(_DWORD *)(this + 3980) = 5;
  v1 = this;
  sub_4B6130((_DWORD *)this);
  result = *(_DWORD **)(this + 2468);
  switch ( (unsigned int)result )
  {
    case 0u:
      *(_DWORD *)(this + 2484) = 16;
      goto LABEL_14;
    case 1u:
      *(_DWORD *)(this + 2484) = 24;
      goto LABEL_14;
    case 2u:
      *(_DWORD *)(this + 2484) = 32;
      goto LABEL_14;
    case 3u:
      *(_DWORD *)(this + 2484) = 48;
      goto LABEL_14;
    case 4u:
      *(_DWORD *)(this + 2484) = 96;
LABEL_14:
      v3 = *(_DWORD *)(this + 2484);
      result = (_DWORD *)sub_587C03(176 * *(_DWORD *)(v1 + 2484) + 4);
      if ( result )
      {
        v4 = result + 1;
        *result = v3;
        result = (_DWORD *)(v3 - 1);
        v5 = v4;
        if ( v3 - 1 >= 0 )
        {
          do
          {
            result = sub_4B46B0(v5);
            v5 += 44;
            --v3;
          }
          while ( v3 );
        }
        *(_DWORD *)(v1 + 2480) = v4;
      }
      else
      {
        *(_DWORD *)(v1 + 2480) = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}
