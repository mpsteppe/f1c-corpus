int __thiscall sub_418720(_DWORD *this, const char *a2, char *Source, int a4)
{
  int v5; // esi
  int result; // eax
  int v7; // edi
  const char *v8; // edx
  const char *v9; // ecx
  char Buffer[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v11; // [esp+8Dh] [ebp-3h]
  char v12; // [esp+8Fh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v11 = 0;
  v12 = 0;
  sprintf(Buffer, "%s%s", a2, Source);
  v5 = 48 * a4;
  *(_DWORD *)(48 * a4 + *this + 44) = sub_418840(Buffer);
  result = 48 * a4 + *this;
  if ( *(_DWORD *)(result + 44) )
  {
    v7 = result + 2;
    strncpy((char *)(result + 2), Source, 0x27u);
    *(_BYTE *)(v7 + 39) = 0;
    v8 = (const char *)(v5 + *this + 2);
    v9 = (const char *)(v5 + *this + strlen(v8) + 2);
    if ( v9 > v8 )
    {
      while ( *v9 != 46 )
      {
        if ( --v9 <= v8 )
          goto LABEL_7;
      }
      *v9 = 0;
    }
LABEL_7:
    strcat((char *)(v5 + *this + 2), ".dat");
    *(_WORD *)(v5 + *this) = sub_58D0E0(*(_DWORD *)(v5 + *this + 44));
    result = v5 + *this;
    if ( *(__int16 *)result < 0 )
    {
      result = sub_5BE8AE(*(LPVOID *)(result + 44));
      *(_DWORD *)(v5 + *this + 44) = 0;
    }
  }
  return result;
}
