int __usercall sub_6360BC@<eax>(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  int result; // eax
  int v4; // eax

  *(_DWORD *)(a2 - 4) = *(_DWORD *)(a1 - 56);
  _FindAndUnlinkFrame(*(struct FrameInfo **)(a1 - 60));
  *(_DWORD *)(_getptd() + 124) = *(_DWORD *)(a1 - 64);
  result = _getptd();
  *(_DWORD *)(result + 128) = *(_DWORD *)(a1 - 68);
  if ( *(_DWORD *)a3 == -529697949 && *(_DWORD *)(a3 + 16) == 3 )
  {
    result = *(_DWORD *)(a3 + 20);
    if ( (result == 429065504 || result == 429065505) && !*(_DWORD *)(a1 - 72) && *(_DWORD *)(a1 - 32) )
    {
      result = IsExceptionObjectToBeDestroyed(*(void **)(a3 + 24));
      if ( result )
      {
        v4 = _abnormal_termination();
        return __DestructExceptionObject(a3, v4);
      }
    }
  }
  return result;
}
