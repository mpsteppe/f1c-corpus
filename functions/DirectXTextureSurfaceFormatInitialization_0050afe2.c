int __thiscall sub_50AFE2(int this, int a2)
{
  BOOL v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // edx

  DirectXTextureCreationWithMipmapChain((float *)this, (float *)a2, 0, 1);
  *(_DWORD *)this = &off_5ADB90;
  if ( *(_DWORD *)(a2 + 24) == 1 )
  {
    *(_DWORD *)(this + 4216) = 0;
  }
  else if ( *(_DWORD *)(a2 + 24) == 2 )
  {
    *(_DWORD *)(this + 4216) = 1;
  }
  else
  {
    *(_DWORD *)(this + 4216) = 3;
  }
  if ( *(_DWORD *)(a2 + 28) == 1 )
  {
    *(_DWORD *)(this + 4220) = 0;
  }
  else if ( *(_DWORD *)(a2 + 28) == 2 )
  {
    *(_DWORD *)(this + 4220) = 1;
  }
  else
  {
    *(_DWORD *)(this + 4220) = 3;
  }
  v3 = *(_DWORD *)(this + 4216) != 3 || *(_DWORD *)(this + 4220) != 3;
  *(_DWORD *)(this + 4212) = v3;
  v4 = *(_DWORD *)(this + 4);
  switch ( v4 )
  {
    case 827611204:
      *(_DWORD *)(this + 4224) = 8;
      *(_DWORD *)(this + 4232) = FileIOWrapper;
      *(_DWORD *)(this + 4228) = KeyframeQuadInterpolationWithBitPackedSelector;
      break;
    case 844388420:
      *(_DWORD *)(this + 4224) = 16;
      *(_DWORD *)(this + 4232) = DelegationWithErrorCheck;
      *(_DWORD *)(this + 4228) = FileOpenAndValidate;
      break;
    case 861165636:
      *(_DWORD *)(this + 4224) = 16;
      *(_DWORD *)(this + 4232) = QuantizationColorSpaceConversion;
      *(_DWORD *)(this + 4228) = sub_51512C;
      break;
    case 877942852:
      *(_DWORD *)(this + 4224) = 16;
      *(_DWORD *)(this + 4232) = InitProcessWrapper;
      *(_DWORD *)(this + 4228) = sub_51588C;
      break;
    case 894720068:
      *(_DWORD *)(this + 4224) = 16;
      *(_DWORD *)(this + 4232) = sub_515417;
      *(_DWORD *)(this + 4228) = sub_5151AF;
      break;
  }
  v5 = *(_DWORD *)(this + 4160);
  v6 = *(_DWORD *)(this + 4144);
  v7 = *(_DWORD *)(this + 4156);
  v8 = *(_DWORD *)(this + 4148);
  *(_DWORD *)(this + 4272) = -1;
  *(_DWORD *)(this + 4276) = -1;
  *(_DWORD *)(this + 4252) = v5;
  v9 = (*(_DWORD *)(this + 4152) + 3) & 0xFFFFFFFC;
  v6 &= 0xFFFFFFFC;
  *(_DWORD *)(this + 4244) = v9;
  v8 &= 0xFFFFFFFC;
  v10 = (v7 + 3) & 0xFFFFFFFC;
  v11 = *(_DWORD *)(this + 4164);
  *(_DWORD *)(this + 4248) = v10;
  *(_DWORD *)(this + 4260) = (v9 - v6) >> 2;
  *(_DWORD *)(this + 4256) = v11;
  v12 = v11 - *(_DWORD *)(this + 4160);
  *(_DWORD *)(this + 4236) = v6;
  *(_DWORD *)(this + 4280) = 0;
  *(_DWORD *)(this + 4284) = 0;
  *(_DWORD *)(this + 4288) = 0;
  *(_DWORD *)(this + 4240) = v8;
  *(_DWORD *)(this + 4264) = (v10 - v8) >> 2;
  *(_DWORD *)(this + 4268) = v12;
  return this;
}
