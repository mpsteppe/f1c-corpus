int __thiscall sub_46A110(int this)
{
  CNet *v2; // eax
  CNet *v3; // eax

  v2 = (CNet *)operator new(0x440u);
  if ( v2 )
    v3 = CNet::CNet(v2, sub_469C10, sub_46A020);
  else
    v3 = 0;
  *(_DWORD *)this = v3;
  CNet::AddRequestKey(v3, 1);
  CNet::AddRequestKey(*(CNet **)this, 2);
  CNet::AddRequestKey(*(CNet **)this, 3);
  CNet::AddRequestKey(*(CNet **)this, 4);
  CNet::AddRequestKey(*(CNet **)this, 5);
  CNet::AddRequestKey(*(CNet **)this, 8);
  CNet::AddRequestKey(*(CNet **)this, 10);
  CNet::AddRequestKey(*(CNet **)this, 11);
  CNet::AddRequestKey(*(CNet **)this, 19);
  *(_BYTE *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_BYTE *)(this + 5) = 1;
  return this;
}
