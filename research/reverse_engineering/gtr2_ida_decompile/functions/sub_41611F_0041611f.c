void __usercall sub_41611F(int a1@<esi>)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 4);
  if ( v1 )
    *(_BYTE *)(v1 + 48) = 0;
  JUMPOUT(0x41615E);
}
