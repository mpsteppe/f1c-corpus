int __thiscall ArrayStateRead(void *this)
{
  int v2; // [esp+0h] [ebp-8h] BYREF

  StringStreamReadWithMaskCheck((int)this, (int)&v2);
  return v2;
}

