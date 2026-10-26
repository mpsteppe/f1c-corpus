int __fastcall sub_5622C0(void *a1, _BYTE *a2, int a3, int a4)
{
  void *v4; // esi
  int result; // eax
  int v6; // ebp
  int (__fastcall *v7)(_BYTE *, int, int); // esi
  char v8; // al
  int v9; // ecx
  char **v10; // ebx
  int v11; // eax
  _BYTE *v12; // edx
  char v13; // cl
  _BYTE v15[256]; // [esp+14h] [ebp-678h] BYREF
  char buf[1397]; // [esp+114h] [ebp-578h] BYREF
  __int16 v17; // [esp+689h] [ebp-3h]
  char v18; // [esp+68Bh] [ebp-1h]

  v4 = a1;
  buf[0] = byte_5EA438[0];
  v15[0] = byte_5EA438[0];
  memset(&buf[1], 0, 0x574u);
  v17 = 0;
  v18 = 0;
  result = 0;
  v6 = 0;
  memset(&v15[1], 0, 255);
  if ( !a1 )
    v4 = off_5E4DFC;
  if ( *a2 == 59 )
  {
    v7 = (int (__fastcall *)(_BYTE *, int, int))*((_DWORD *)v4 + 63);
    if ( v7 )
      return v7(a2, a3, a4);
  }
  else
  {
    v8 = *((_BYTE *)v4 + 232);
    v9 = *((_DWORD *)v4 + 55) + 1;
    *((_DWORD *)v4 + 56) = 0;
    *((_DWORD *)v4 + 55) = v9;
    if ( v8 > 0 )
      *((_BYTE *)v4 + 232) = 0;
    v10 = off_5E4CD4;
    do
    {
      v11 = sub_562530(a2, *v10);
      if ( v11 )
      {
        switch ( v6 )
        {
          case 0:
            StackBufferZeroInitWithCallback(buf);
            break;
          case 1:
            StackBufferZeroInitWithVTableCall(buf);
            break;
          case 2:
            BufferZeroInitWithVirtualMethodCall(buf);
            break;
          case 3:
            LargeStackStructZeroInitWithVtableCall(buf);
            break;
          case 4:
            StackBufferZeroInitWithCallback(buf);
            StackBufferZeroInitWithVTableCall(buf);
            BufferZeroInitWithVirtualMethodCall(buf);
            LargeStackStructZeroInitWithVtableCall(buf);
            break;
          case 5:
            StackBufferZeroInitWithCallback(buf);
            sub_562610(buf);
            StackBufferZeroInitWithVTableCall(buf);
            sub_562610(buf);
            BufferZeroInitWithVirtualMethodCall(buf);
            sub_562610(buf);
            LargeStackStructZeroInitWithVtableCall(buf);
            break;
          case 6:
            sub_562950(buf, v11);
            break;
          case 7:
            v12 = &v15[-v11];
            do
            {
              v13 = *(_BYTE *)v11;
              v12[v11] = *(_BYTE *)v11;
              ++v11;
            }
            while ( v13 );
            break;
          default:
            break;
        }
      }
      ++v10;
      ++v6;
    }
    while ( v6 + 1 <= 8 );
    return sub_5629B0(buf, (int)v15);
  }
  return result;
}
