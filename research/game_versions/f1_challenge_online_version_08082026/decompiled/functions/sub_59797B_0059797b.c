int __cdecl sub_59797B(int a1, LONG lDistanceToMove)
{
  int v2; // esi
  DWORD v3; // eax
  int v4; // edi
  DWORD v5; // eax
  int v6; // eax
  void *v7; // eax
  BOOL v8; // eax
  DWORD LastError; // edi
  unsigned __int8 Buffer[4096]; // [esp+8h] [ebp-1004h] BYREF
  LONG v12; // [esp+1008h] [ebp-4h]
  LONG lDistanceToMovea; // [esp+1018h] [ebp+Ch]

  v2 = 0;
  v12 = sub_58C789(a1, 0, 1u);
  if ( v12 == -1 )
    return -1;
  v3 = sub_58C789(a1, 0, 2u);
  if ( v3 == -1 )
    return -1;
  v4 = lDistanceToMove - v3;
  if ( (int)(lDistanceToMove - v3) <= 0 )
  {
    if ( (int)(lDistanceToMove - v3) < 0 )
    {
      sub_58C789(a1, lDistanceToMove, 0);
      v7 = (void *)sub_595A1F(a1);
      v8 = SetEndOfFile(v7);
      v2 = v8 - 1;
      if ( !v8 )
      {
        *(_DWORD *)sub_58AFCF() = 13;
        LastError = GetLastError();
        *(_DWORD *)sub_58AFD8() = LastError;
      }
    }
  }
  else
  {
    sub_58BB10(Buffer, 0, 0x1000u);
    lDistanceToMovea = sub_59801A(a1, 0x8000);
    while ( 1 )
    {
      v5 = 4096;
      if ( v4 < 4096 )
        v5 = v4;
      v6 = sub_58E290(a1, Buffer, v5);
      if ( v6 == -1 )
        break;
      v4 -= v6;
      if ( v4 <= 0 )
        goto LABEL_13;
    }
    if ( *(_DWORD *)sub_58AFD8() == 5 )
      *(_DWORD *)sub_58AFCF() = 13;
    v2 = -1;
LABEL_13:
    sub_59801A(a1, lDistanceToMovea);
  }
  sub_58C789(a1, v12, 0);
  return v2;
}
