// positive sp value has been detected, the output may be wrong!
int __usercall sub_4F14D7@<eax>(int a1@<esi>)
{
  DNameNode *v1; // eax
  DNameNode *v2; // esi
  int v3; // eax
  DNameNode *v6; // [esp-4h] [ebp-Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-8h]
  int retaddr; // [esp+8h] [ebp+0h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( !dword_B6F384 )
  {
    v1 = (DNameNode *)operator new(0xCu);
    v2 = v1;
    v6 = v1;
    retaddr = 0;
    if ( v1 )
    {
      DNameNode::DNameNode(v1);
      *(_DWORD *)v2 = &off_7146B4;
      *((_DWORD *)v2 + 2) = 0;
    }
    else
    {
      v2 = 0;
    }
    retaddr = -1;
    dword_B6F384 = (int)v2;
    v3 = sub_5A8CA0(v2, a1, v6, ExceptionList);
    ((void (__thiscall *)(int))sub_5A8B70)(v3);
  }
  return sub_4F1270((_DWORD *)dword_B6F384);
}
