// positive sp value has been detected, the output may be wrong!
int __usercall sub_5C6157@<eax>(int a1@<esi>)
{
  DNameNode *v1; // eax
  DNameNode *v2; // esi
  int v5; // [esp-4h] [ebp-Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-8h]
  int retaddr; // [esp+8h] [ebp+0h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( !dword_FB22FC )
  {
    v1 = (DNameNode *)operator new(0xCu);
    v2 = v1;
    v5 = (int)v1;
    retaddr = 0;
    if ( v1 )
    {
      DNameNode::DNameNode(v1);
      *(_DWORD *)v2 = &off_72A1E8;
      *((_DWORD *)v2 + 2) = 0;
    }
    else
    {
      v2 = 0;
    }
    retaddr = -1;
    dword_FB22FC = (int)v2;
    sub_5A8CA0((int)v2, a1, v5, (int)ExceptionList);
    sub_5A8B70();
  }
  return sub_5C5AC0((_DWORD *)dword_FB22FC);
}
