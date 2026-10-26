char __fastcall sub_568B00(int a1, int a2)
{
  int v3; // esi
  int v4; // edi
  int i; // eax
  _BYTE v7[2048]; // [esp+8h] [ebp-800h] BYREF

  v3 = sub_587DB0(a1, aRb);
  if ( !v3 )
    return 0;
  v4 = sub_587DB0(a2, &unk_5C2AB0);
  if ( !v4 )
  {
    FileCloseWithLock(v3);
    return 0;
  }
  for ( i = ThreadSafeReadWrapper_803f(v7, 1, 2048, v3); i > 0; i = ThreadSafeReadWrapper_803f(v7, 1, 2048, v3) )
    FileReadWrapperWithLock(v7, 1, i, v4);
  FileCloseWithLock(v3);
  FileCloseWithLock(v4);
  return 1;
}
