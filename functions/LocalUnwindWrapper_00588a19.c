int __stdcall LocalUnwindWrapper(int a1)
{
  return MSVCRTSEHFrameUnwinder(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 28));
}
