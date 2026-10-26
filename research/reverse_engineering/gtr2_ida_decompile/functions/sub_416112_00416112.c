void __usercall sub_416112(int a1@<esi>)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 4);
  if ( v1 )
    *(_BYTE *)(v1 + 48) = 1;
  JUMPOUT(0x41615E);
}
