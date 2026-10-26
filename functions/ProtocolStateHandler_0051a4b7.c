void __cdecl sub_51A4B7(int a1)
{
  int v1; // edi

  v1 = *(_DWORD *)(a1 + 388);
  if ( *(_DWORD *)(v1 + 16) )
  {
    if ( *(_BYTE *)(a1 + 73) && RenderStateCopyWithValidation(a1) )
      *(_DWORD *)(v1 + 12) = AudioSubbandSynthesisFilterbank;
    else
      *(_DWORD *)(v1 + 12) = DrawableObjectBatchProcessor;
  }
  *(_DWORD *)(a1 + 136) = 0;
}
