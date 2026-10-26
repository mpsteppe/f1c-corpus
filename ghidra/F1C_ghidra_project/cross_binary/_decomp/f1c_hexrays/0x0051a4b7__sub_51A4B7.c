// f1c  0x0051a4b7  size=59
void __cdecl sub_51A4B7(int a1)
{
  int v1; // edi

  v1 = *(_DWORD *)(a1 + 388);
  if ( *(_DWORD *)(v1 + 16) )
  {
    if ( *(_BYTE *)(a1 + 73) && sub_519EB7(a1) )
      *(_DWORD *)(v1 + 12) = sub_519F9A;
    else
      *(_DWORD *)(v1 + 12) = sub_519D51;
  }
  *(_DWORD *)(a1 + 136) = 0;
}
