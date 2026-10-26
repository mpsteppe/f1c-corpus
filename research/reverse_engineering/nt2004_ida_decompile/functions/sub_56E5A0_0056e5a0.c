_DWORD *__thiscall sub_56E5A0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // edi
  DWORD v3; // eax
  _DWORD *v4; // ebp
  _DWORD *result; // eax
  bool v6; // zf
  int v7; // esi
  _DWORD *v8; // edi
  _DWORD *v9; // ecx
  void *v10; // eax
  void *v11; // edi
  void *v12; // edi
  _DWORD *v13; // [esp+10h] [ebp-8h]

  v1 = (void *)this[687];
  v2 = this + 683;
  v13 = this + 683;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[688])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  result = (_DWORD *)*v4;
  v6 = *v4 == 0;
  v4[2] = *v4;
  if ( !v6 )
  {
    v7 = *result;
    if ( *result )
    {
      while ( 1 )
      {
        v8 = result;
        v9 = 0;
        if ( result )
        {
          while ( *v8 != v7 )
          {
            v9 = v8;
            v8 = (_DWORD *)v8[1];
            if ( !v8 )
              goto LABEL_25;
          }
          if ( v8 == (_DWORD *)v4[2] )
            v4[2] = v8[1];
          if ( v9 )
            v9[1] = v8[1];
          else
            *v4 = v8[1];
          if ( (_DWORD *)v4[1] == v8 )
            v4[1] = v9;
          --v4[3];
          sub_572310(v8);
          sub_5BE8AE();
          v10 = (void *)this[763];
          if ( v10 )
            WaitForSingleObject(v10, this[764]);
          *(_WORD *)(v7 + 2102) = 0;
          *(_WORD *)(v7 + 2104) = 0;
          *(_WORD *)(v7 + 18490) = 0;
          *(_WORD *)(v7 + 18492) = 0;
          *(_DWORD *)v7 = 0;
          *(_DWORD *)(v7 + 4) = 0;
          *(_DWORD *)(v7 + 8) = 0;
          *(_DWORD *)(v7 + 12) = 0;
          *(_DWORD *)(v7 + 16) = 0;
          *(_DWORD *)(v7 + 20) = 0;
          *(_DWORD *)(v7 + 24) = 0;
          *(_DWORD *)(v7 + 28) = 0;
          *(_DWORD *)(v7 + 32) = -1;
          *(_DWORD *)(v7 + 36) = 0;
          *(_BYTE *)(v7 + 40) = 0;
          *(_DWORD *)(v7 + 44) = 0;
          *(_DWORD *)(v7 + 48) = 0;
          *(_WORD *)(v7 + 52) = 0;
          sub_5765C0(v7, 0);
          v11 = (void *)this[763];
          if ( v11 )
            ReleaseMutex(v11);
          result = (_DWORD *)*v4;
          v6 = *v4 == 0;
          v4[2] = *v4;
          if ( v6 )
          {
LABEL_26:
            v2 = v13;
            break;
          }
          v7 = *result;
        }
LABEL_25:
        if ( !v7 )
          goto LABEL_26;
      }
    }
  }
  v12 = (void *)v2[4];
  if ( v12 )
    return (_DWORD *)ReleaseMutex(v12);
  return result;
}
