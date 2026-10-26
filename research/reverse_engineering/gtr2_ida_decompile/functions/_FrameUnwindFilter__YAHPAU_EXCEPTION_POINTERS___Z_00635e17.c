int __usercall FrameUnwindFilter@<eax>(_DWORD **a1@<eax>)
{
  if ( **a1 == -529697949 )
  {
    *(_DWORD *)(_getptd() + 132) = 0;
    terminate();
  }
  return 0;
}
