char __fastcall sub_568A60(int a1, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4)
{
  int v4; // edi
  int v6; // esi
  int i; // eax

  *a4 = 0;
  v4 = sub_587DB0(a1, aRb);
  if ( !v4 )
    return 0;
  if ( !a2 )
    a2 = 1;
  *a4 = 0;
  sub_587F64(v4, 0, 0);
  v6 = a3;
  for ( i = StreamGetcWithUnderflowHandler(v4); i != -1; i = StreamGetcWithUnderflowHandler(v4) )
  {
    *a4 += v6 * i;
    v6 = (v6 + 1) % a2;
  }
  FileCloseWithLock(v4);
  return 1;
}

