int __thiscall sub_59A2FE(int *this)
{
  if ( this[20] && LockCallUnlockWrapper(this[20]) < 0 )
    return -1;
  else
    return 0;
}
