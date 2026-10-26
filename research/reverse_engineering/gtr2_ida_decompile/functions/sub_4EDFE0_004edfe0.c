int __thiscall sub_4EDFE0(int this)
{
  int i; // edi
  int result; // eax

  *(_DWORD *)(this + 372) = 2139095039;
  *(_DWORD *)(this + 376) = 2139095039;
  *(_DWORD *)(this + 380) = 2139095039;
  *(_DWORD *)(this + 384) = 2139095039;
  *(_DWORD *)(this + 388) = 2139095039;
  *(_DWORD *)(this + 392) = 2139095039;
  *(_DWORD *)(this + 396) = 2139095039;
  *(_DWORD *)(this + 408) = 2139095039;
  *(_DWORD *)(this + 412) = 2139095039;
  *(_DWORD *)(this + 416) = 2139095039;
  *(_DWORD *)(this + 420) = 2139095039;
  *(_DWORD *)(this + 400) = 2139095039;
  *(_DWORD *)(this + 404) = 2139095039;
  *(_DWORD *)(this + 424) = 2139095039;
  *(_DWORD *)(this + 428) = 0;
  *(_DWORD *)(this + 432) = 0;
  *(_DWORD *)(this + 436) = 0;
  *(_BYTE *)(this + 440) = 0;
  *(_BYTE *)(this + 441) = 0;
  for ( i = 0; i < 93; ++i )
  {
    result = *(_DWORD *)(this + 4 * i);
    if ( result )
      result = (*(int (**)(void))(*(_DWORD *)result + 8))();
  }
  return result;
}
