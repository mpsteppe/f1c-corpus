// positive sp value has been detected, the output may be wrong!
void __usercall __noreturn sub_401476(__int64 a1@<edx:eax>, int a2@<ecx>)
{
  __int16 v2; // [esp-4h] [ebp-4h]

  _disable();
  _disable();
  _disable();
  _disable();
  _enable();
  _enable();
  _enable();
  _enable();
  while ( 1 )
    a1 = (int)*MK_FP(v2, HIDWORD(a1) + 1) * (__int64)(-85 * *MK_FP(v2, a2));
}
