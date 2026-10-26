void __cdecl sub_51EA90(_DWORD *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  void **v4; // ebx
  bool v5; // zf
  int v6; // edi
  unsigned int i; // ebp

  v1 = a1[105];
  a1[29] = *(_DWORD *)(v1 + 16);
  a1[28] = *(_DWORD *)(v1 + 20);
  v2 = a1[19];
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        *(_BYTE *)(v1 + 84) = 0;
        v4 = (void **)(v1 + 68);
        v5 = *(_DWORD *)(v1 + 68) == 0;
        *(_DWORD *)(v1 + 4) = PixelDataConvolutionViaLookupTable;
        if ( v5 )
          VirtualArrayFill(a1);
        v6 = 0;
        for ( i = 2 * a1[23] + 4; v6 < a1[25]; ++v4 )
        {
          MemoryZeroFill(*v4, i);
          ++v6;
        }
      }
      else
      {
        *(_DWORD *)(*a1 + 20) = 47;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
    }
    else
    {
      if ( a1[25] == 3 )
        *(_DWORD *)(v1 + 4) = AudioSynthesis3ChannelSampleGenerator;
      else
        *(_DWORD *)(v1 + 4) = ChecksumComputeType1;
      v5 = *(_BYTE *)(v1 + 28) == 0;
      *(_DWORD *)(v1 + 48) = 0;
      if ( v5 )
        sub_51E3E7(a1);
      if ( !*(_DWORD *)(v1 + 52) )
        PerIndexTableGenerationWithDivision((int)a1);
    }
  }
  else if ( a1[25] == 3 )
  {
    *(_DWORD *)(v1 + 4) = ChecksumComputeType03Stream;
  }
  else
  {
    *(_DWORD *)(v1 + 4) = TableWeightedMix;
  }
}

