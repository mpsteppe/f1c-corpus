// positive sp value has been detected, the output may be wrong!
void __usercall sub_45BED6(int a1@<edi>, int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 68) != a1 )
  {
    sub_53CB90(*(_DWORD *)(a2 + 68));
    *(_DWORD *)(a2 + 68) = a1;
  }
  if ( *(_DWORD *)(a2 + 80) != a1 )
  {
    FreeWrapper_7bcf(*(LPVOID *)(a2 + 80));
    *(_DWORD *)(a2 + 80) = a1;
  }
  WideStructZeroInit(a2);
  AVIFileExit();
}

