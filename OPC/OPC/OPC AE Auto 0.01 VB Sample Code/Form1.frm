VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7545
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10125
   LinkTopic       =   "Form1"
   ScaleHeight     =   7545
   ScaleWidth      =   10125
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame fraCategories 
      Caption         =   "Event Categories"
      Height          =   2655
      Left            =   120
      TabIndex        =   24
      Top             =   4680
      Visible         =   0   'False
      Width           =   9855
      Begin VB.CommandButton cmdSetAttributes 
         Caption         =   "Set Attributes"
         Height          =   495
         Left            =   6240
         TabIndex        =   33
         Top             =   600
         Width           =   1215
      End
      Begin VB.ListBox lstConditionNames 
         Height          =   840
         Left            =   3600
         TabIndex        =   30
         Top             =   1680
         Width           =   2415
      End
      Begin VB.ListBox lstSubConditionNames 
         Height          =   840
         Left            =   7440
         TabIndex        =   29
         Top             =   1680
         Width           =   2055
      End
      Begin VB.ListBox lstCategories 
         Height          =   1815
         ItemData        =   "Form1.frx":0000
         Left            =   240
         List            =   "Form1.frx":0002
         TabIndex        =   26
         Top             =   600
         Width           =   2175
      End
      Begin VB.ListBox lstAttributes 
         Height          =   840
         Left            =   3600
         MultiSelect     =   2  'Extended
         TabIndex        =   25
         Top             =   600
         Width           =   2415
      End
      Begin VB.Label lblConditions 
         Alignment       =   1  'Right Justify
         Caption         =   "Conditions:"
         Height          =   255
         Left            =   2640
         TabIndex        =   32
         Top             =   1680
         Width           =   855
      End
      Begin VB.Label lblSubConditionNames 
         Caption         =   "Sub Conditions:"
         Height          =   255
         Left            =   6240
         TabIndex        =   31
         Top             =   1680
         Width           =   1215
      End
      Begin VB.Label lblCategories 
         Alignment       =   2  'Center
         Appearance      =   0  'Flat
         BackColor       =   &H80000005&
         BackStyle       =   0  'Transparent
         Caption         =   "Categories"
         ForeColor       =   &H80000008&
         Height          =   255
         Left            =   240
         TabIndex        =   28
         Top             =   360
         Width           =   2055
      End
      Begin VB.Label lblAttributes 
         Alignment       =   1  'Right Justify
         Caption         =   "Attributes:"
         Height          =   255
         Left            =   2640
         TabIndex        =   27
         Top             =   600
         Width           =   855
      End
   End
   Begin VB.Frame fraSubscription1 
      Caption         =   "Event Subscription"
      Enabled         =   0   'False
      Height          =   2535
      Left            =   120
      TabIndex        =   9
      Top             =   2040
      Visible         =   0   'False
      Width           =   9855
      Begin VB.CommandButton cmdRefresh1 
         Caption         =   "Refresh"
         Height          =   495
         Left            =   120
         TabIndex        =   21
         Top             =   600
         Width           =   1215
      End
      Begin VB.CheckBox chkActivateSubscription1 
         Caption         =   "Active?"
         Height          =   255
         Left            =   120
         TabIndex        =   17
         Top             =   240
         Width           =   2055
      End
      Begin VB.ListBox lstRefreshEvents1 
         Height          =   645
         Left            =   4320
         TabIndex        =   16
         Top             =   1680
         Width           =   5175
      End
      Begin VB.ListBox lstEventList1 
         Height          =   1035
         Left            =   4320
         TabIndex        =   15
         Top             =   480
         Width           =   5175
      End
      Begin VB.TextBox txtBufferTime1 
         Height          =   375
         Left            =   1080
         TabIndex        =   14
         Text            =   "10000"
         Top             =   1320
         Width           =   1215
      End
      Begin VB.CommandButton cmdBufferTime1 
         Caption         =   "Set"
         Height          =   375
         Left            =   2400
         TabIndex        =   13
         ToolTipText     =   "Set the Buffer Time for Subscription 1"
         Top             =   1320
         Width           =   855
      End
      Begin VB.CommandButton cmdMaxSize1 
         Caption         =   "Set"
         Height          =   375
         Left            =   2400
         TabIndex        =   12
         ToolTipText     =   "Set the Maximum size for Event callbacks on Subscription 1"
         Top             =   1800
         Width           =   855
      End
      Begin VB.TextBox txtMaxSize1 
         Height          =   375
         Left            =   1080
         TabIndex        =   11
         Text            =   "1000"
         Top             =   1800
         Width           =   1215
      End
      Begin VB.CommandButton cmdCancelRefresh1 
         Caption         =   "Cancel Refresh"
         Height          =   495
         Left            =   1560
         TabIndex        =   10
         Top             =   600
         Width           =   1455
      End
      Begin VB.Label lblMaxSize 
         Alignment       =   1  'Right Justify
         Caption         =   "Max Size:"
         Height          =   255
         Left            =   120
         TabIndex        =   22
         Top             =   1800
         Width           =   855
      End
      Begin VB.Label lblBufferTime1 
         Alignment       =   1  'Right Justify
         Caption         =   "Buffer Time:"
         Height          =   255
         Left            =   120
         TabIndex        =   20
         Top             =   1320
         Width           =   855
      End
      Begin VB.Label lblConditionEvents 
         Alignment       =   1  'Right Justify
         Caption         =   "Events:"
         Height          =   495
         Left            =   3600
         TabIndex        =   19
         Top             =   480
         Width           =   615
      End
      Begin VB.Label lblRefreshedEvents 
         Alignment       =   1  'Right Justify
         Caption         =   "Refreshed Events:"
         Height          =   495
         Left            =   3360
         TabIndex        =   18
         Top             =   1680
         Width           =   855
      End
   End
   Begin VB.Frame fraEventServer 
      Caption         =   "OPC Event Server"
      Height          =   1455
      Left            =   120
      TabIndex        =   1
      Top             =   0
      Width           =   9855
      Begin VB.CommandButton cmdSubscriptionDefaults 
         Caption         =   "Subscription Defaults"
         Enabled         =   0   'False
         Height          =   495
         Left            =   6240
         TabIndex        =   23
         Top             =   840
         Width           =   1935
      End
      Begin VB.ComboBox cboProgIDs 
         Height          =   315
         Left            =   2280
         TabIndex        =   8
         Text            =   "Combo1"
         Top             =   720
         Width           =   3135
      End
      Begin VB.TextBox txtServerNode 
         Height          =   285
         Left            =   2280
         TabIndex        =   5
         Text            =   "<local>"
         Top             =   360
         Width           =   3135
      End
      Begin VB.CommandButton cmdServerProperties 
         Caption         =   "Server Properties"
         Enabled         =   0   'False
         Height          =   495
         Left            =   6240
         TabIndex        =   4
         Top             =   240
         Width           =   1935
      End
      Begin VB.CommandButton cmdDisconnectServer 
         Caption         =   "Disconnect"
         Enabled         =   0   'False
         Height          =   495
         Left            =   240
         TabIndex        =   3
         Top             =   840
         Width           =   1215
      End
      Begin VB.CommandButton cmdConnectServer 
         Caption         =   "Connect"
         Height          =   495
         Left            =   240
         TabIndex        =   2
         Top             =   240
         Width           =   1215
      End
      Begin VB.Label lblProgID 
         Alignment       =   1  'Right Justify
         Caption         =   "ProgID:"
         Height          =   255
         Left            =   1560
         TabIndex        =   7
         Top             =   720
         Width           =   615
      End
      Begin VB.Label lblServerNode 
         Alignment       =   1  'Right Justify
         Caption         =   "Node:"
         Height          =   255
         Left            =   1680
         TabIndex        =   6
         Top             =   360
         Width           =   495
      End
   End
   Begin VB.CheckBox chkSubscription1 
      Caption         =   "Add Subscription 1"
      Enabled         =   0   'False
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   1680
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

' Declare the server object
'  - declared WithEvents to allow for EventServerShutDown event to come through
'Public WithEvents objEventServer As OPC_AUTO_AELib.OpcEventServer

'Wrapper doesn't seem to support events right now
Public objEventServer As OPC_AUTO_AELib.OpcEventServer
Attribute objEventServer.VB_VarHelpID = -1


' Declare variable to reference the Subscriptions collection
Public objSubscriptions As OPC_AUTO_AELib.OPCEventSubscriptions

' Declare variables for the subscriptions themselves
'  - each one declared WithEvents to catch new "Event" events
Public WithEvents objSubscription1 As OPC_AUTO_AELib.OpcEventSubscription
Attribute objSubscription1.VB_VarHelpID = -1
'Public WithEvents objSubscription2 As OPC_AUTO_AELib.OpcEventSubscription
'Public WithEvents objSubscription3 As OPC_AUTO_AELib.OpcEventSubscription

Const cTxtLocalServerText As String = "<Local>"
Const cLineFeed As Integer = 10
Const cTab As Integer = 9

Private Sub cmdConditionNames_Click()
    lstConditionNames.Clear
    lstSubConditionNames.Clear
    
    Dim CondNames As Variant
    Dim SubConditionName As Variant
    CondNames = objEventServer.QueryConditionNames(1)
    
    Dim X As Integer
    For X = LBound(CondNames) To UBound(CondNames)
        lstConditionNames.AddItem CondNames(X)
    Next
    
    SubConditionName = objEventServer.QuerySubConditionNames(CondNames(0))
    For X = LBound(SubConditionName) To UBound(SubConditionName)
        lstSubConditionNames.AddItem SubConditionName(X)
    Next
    
End Sub

Private Sub cmdConnectServer_Click()
    subServerConnect
End Sub

Private Sub cmdDisconnectServer_Click()
  subServerDisconnect
End Sub

Private Sub cmdServerProperties_Click()
  
Dim varLocaleIDs As Variant 'array of supported localeIDs
Dim strLocaleIDs As String  'string built out of Variant
Dim intLocaleIndx As Integer
  
varLocaleIDs = objEventServer.LocaleIds

For intLocaleIndx = LBound(varLocaleIDs) To UBound(varLocaleIDs)
   If Len(strLocaleIDs) > 0 Then
    strLocaleIDs = strLocaleIDs & ", "
    End If
    strLocaleIDs = strLocaleIDs & varLocaleIDs(intLocaleIndx)
Next intLocaleIndx

 MsgBox "Server Properties for: " & Chr(cTab) & Chr(cTab) & objEventServer.ServerName & Chr(cLineFeed) & _
  "On node: " & Chr(cTab) & Chr(cTab) & objEventServer.ServerNode & Chr(cLineFeed) & Chr(cLineFeed) & _
    "Build Number:  " & Chr(cTab) & Chr(cTab) & objEventServer.BuildNumber & Chr(cLineFeed) & _
    "Filters By Area:  " & Chr(cTab) & Chr(cTab) & objEventServer.FiltersByArea & Chr(cLineFeed) & _
    "Filters By Category:  " & Chr(cTab) & Chr(cTab) & objEventServer.FiltersByCategory & Chr(cLineFeed) & _
    "Filters By Severity:  " & Chr(cTab) & Chr(cTab) & objEventServer.FiltersBySeverity & Chr(cLineFeed) & _
    "Filters By Source:  " & Chr(cTab) & Chr(cTab) & objEventServer.FiltersBySource & Chr(cLineFeed) & _
    "Last Update Time:  " & Chr(cTab) & Chr(cTab) & objEventServer.LastUpdateTime & Chr(cLineFeed) & _
    "Locale ID:  " & Chr(cTab) & Chr(cTab) & objEventServer.LocaleID & Chr(cLineFeed) & _
    "Major Version:  " & Chr(cTab) & Chr(cTab) & objEventServer.MajorVersion & Chr(cLineFeed) & _
    "Minor Version:  " & Chr(cTab) & Chr(cTab) & objEventServer.MinorVersion & Chr(cLineFeed) & _
    "Server State:  " & Chr(cTab) & Chr(cTab) & objEventServer.ServerState & Chr(cLineFeed) & _
    "Start Date:  " & Chr(cTab) & Chr(cTab) & objEventServer.StartDate & Chr(cLineFeed) & _
    "Vendor Info:  " & Chr(cTab) & Chr(cTab) & objEventServer.VendorInfo & Chr(cLineFeed) & _
    "Supported LocaleIDs(" & intLocaleIndx & "):  " & Chr(cTab) & strLocaleIDs & Chr(cLineFeed) & _
    Chr(cLineFeed) & "End of Server Properties."
    
End Sub

Private Sub cmdShowCategories_Click()
    lstCategories.Clear
    lstAttributes.Clear
    Dim Categories As OPC_AUTO_AELib.OPCEventCategories
    Dim Cat As OPC_AUTO_AELib.OpcEventCategory
    Dim Attributes As OPC_AUTO_AELib.OpcEventAttributes
    Dim attr As OPC_AUTO_AELib.OpcEventAttribute
    
    Set Categories = objEventServer.OPCEventCategories
    For Each Cat In Categories
        lstCategories.AddItem Cat.CategoryName & ", " & Str$(Cat.CategoryId)
        lstAttributes.AddItem Cat.CategoryName
        Set Attributes = objEventServer.QueryEventAttributes(Cat.CategoryId)
        For Each attr In Attributes
            lstAttributes.AddItem attr.AttributeName & ", " & Str$(attr.AttributeID) & ", " & attr.AttributeType
        Next
    Next

End Sub

Private Sub cmdShowLocaleIds_Click()
    lstLocaleIds.Clear
    Dim size As Long
    Dim LocaleIds As Variant
    LocaleIds = objEventServer.LocaleIds
    
    Dim X As Integer
    For X = LBound(LocaleIds) To UBound(LocaleIds)
        lstLocaleIds.AddItem LocaleIds(X)
    Next
End Sub

Private Sub chkSubscription1_Click()
    If (chkSubscription1) Then
        Set objSubscription1 = objSubscriptions.Add("Subscript 1")
        fraSubscription1.Enabled = True
        fraSubscription1.Visible = True
    Else
        objSubscriptions.Remove ("Subscript 1")
        fraSubscription1.Enabled = False
        fraSubscription1.Visible = False
    End If
End Sub

Private Sub chkActivateSubscription1_Click()
    Dim check As Boolean
    check = False
    If (chkActivateSubscription1) Then check = True
    objSubscription1.Active = check
End Sub

Private Sub cmdBufferTime1_Click()
    Dim BufferTime As Long
    BufferTime = txtBufferTime1
    objSubscription1.BufferTime = BufferTime
End Sub

Private Sub cmdMaxSize1_Click()
    Dim MaxSize As Long
    MaxSize = txtBufferTime1
    objSubscription1.MaxSize = MaxSize
End Sub

Private Sub cmdRefresh1_Click()
    objSubscription1.Refresh
End Sub

Private Sub CancelRefresh1_Click()
'    objSubscription1.Refresh
    objSubscription1.RefreshCancel
End Sub

Private Sub cmdRemoveAll_Click()
    Dim check As Boolean
    check = False
    
    If (chkActivateSubscription1) Then
        chkActivateSubscription1 = check
        objSubscription1.Active = check
    End If
 
    If (chkSubscription1) Then
        chkSubscription1 = check
    End If
   
'    objSubscriptions.RemoveAll
    
    lstEventList1.Clear
    
    lstRefreshEvents1.Clear
    
    lstCategories.Clear
    lstAttributes.Clear
    lstConditionNames.Clear
    lstSubConditionNames.Clear
    
End Sub


Private Sub cmdSetAttributes_Click()

  subSetEventAttributes (lstCategories.ItemData(lstCategories.ListIndex))
  
End Sub

Private Sub cmdSubscriptionDefaults_Click()

    MsgBox "Subscription Defaults:" & Chr(cLineFeed) & Chr(cLineFeed) & _
        "Default Active:  " & Chr(cTab) & Chr(cTab) & objEventServer.OPCEventSubscriptions.DefaultActive & Chr(cLineFeed) & _
        "Default Buffer Time:  " & Chr(cTab) & objEventServer.OPCEventSubscriptions.DefaultBufferTime & Chr(cLineFeed) & _
        "Default Max Size:  " & Chr(cTab) & Chr(cTab) & objEventServer.OPCEventSubscriptions.DefaultMaxSize & Chr(cLineFeed) & _
        Chr(cLineFeed) & "End."

End Sub

Private Sub Form_Load()
    Set objEventServer = New OpcEventServer
    
    subBrowseServers (txtServerNode.Text)
    
    Set objSubscriptions = objEventServer.OPCEventSubscriptions

End Sub

Private Sub Form_Unload(Cancel As Integer)
    
    Set objSubscriptions = Nothing
    Set objEventServer = Nothing

End Sub




Private Sub lstCategories_Click()

    subAddCategoryInformation (lstCategories.ItemData(lstCategories.ListIndex))

End Sub

Private Sub lstConditionNames_Click()

    subAddSubConditionNames (lstConditionNames.Text)
    
End Sub

Private Sub objSubscription1_ConditionEvent(pVal As Object)
    Dim Events As OPC_AUTO_AELib.OpcEvents
    Dim OPCEvent As OPC_AUTO_AELib.OPCEvent
    
    Set Events = pVal
    For Each OPCEvent In Events
        lstEventList1.AddItem objSubscription1.Name & ", " & OPCEvent.Source & ", " & OPCEvent.Message & ", " & OPCEvent.ConditionName & ", " & OPCEvent.SubConditionName
    Next
    
 '   Dim check As Boolean
 '   check = False
    
  '  If (chkActivateSubscription1) Then
  '      chkActivateSubscription1 = check
  '      objSubscription1.Active = check
  '  End If
    
    Dim ackErrors As Variant
    ackErrors = objEventServer.AckCondition("autoAck", "none", Events)
End Sub


Private Sub objSubscription1_RefreshComplete()
    lstRefreshEvents1.AddItem "Refresh Complete"
End Sub

Private Sub objSubscription1_RefreshConditionEvent(pVal As Object)
    Dim Events As OPC_AUTO_AELib.OpcEvents
    Dim OPCEvent As OPC_AUTO_AELib.OPCEvent
    Dim idx As Integer

    Set Events = pVal
    For idx = 1 To Events.Count
    Set OPCEvent = Events.Item(idx)
        lstRefreshEvents1.AddItem objSubscription1.Name & ", " & OPCEvent.Source & ", " & OPCEvent.Message & ", " & OPCEvent.ConditionName & ", " & OPCEvent.SubConditionName
    Next
End Sub

Private Sub subBrowseServers(txtNode As String)
    Dim ProgIds As Variant
    Dim intProgIdIndx
    
    Me.MousePointer = vbHourglass
    cboProgIDs.Clear
'    If txtNode <> cTxtLocalServerText And txtNode <> "" Then
        ProgIds = objEventServer.GetOPCEventServers(txtNode)
'    Else
'        ProgIds = objEventServer.GetOPCEventServers()
'    End If
    
    If TypeName(ProgIds) = "String()" Then
        For intProgIdIndx = LBound(ProgIds) To UBound(ProgIds)
            cboProgIDs.AddItem ProgIds(intProgIdIndx)
        Next intProgIdIndx
    End If
    cboProgIDs.ListIndex = 0
    Me.MousePointer = vbDefault
End Sub

Private Sub txtServerNode_LostFocus()

If txtServerNode.Enabled = True Then
    subBrowseServers txtServerNode.Text
End If

End Sub

Private Sub subBrowseCategories()

Dim intListIndex As Integer
Dim objCategories As OPC_AUTO_AELib.OPCEventCategories

    lstCategories.Clear
    Set objCategories = objEventServer.OPCEventCategories
    For intListIndex = 1 To objCategories.Count
        lstCategories.AddItem _
            objCategories(intListIndex).CategoryName, _
            intListIndex - 1
        lstCategories.ItemData(intListIndex - 1) = objCategories(intListIndex).CategoryId
    Next intListIndex
    
    lstCategories.ListIndex = 0
    subAddCategoryInformation (lstCategories.ItemData(lstCategories.ListIndex))
End Sub

Private Sub subAddCategoryInformation(intCatID As Integer)

Dim varAttributes As OPC_AUTO_AELib.OpcEventAttributes
Dim varConditions As Variant
Dim strTemp As String
Dim intIndex As Integer

' Display the Attributes
lstAttributes.Clear
Set varAttributes = objEventServer.QueryEventAttributes(intCatID)
For intIndex = 1 To varAttributes.Count 'LBound(varAttributes) To UBound(varAttributes)
  lstAttributes.AddItem varAttributes(intIndex).AttributeName, intIndex - 1
  lstAttributes.ItemData(intIndex - 1) = varAttributes(intIndex).AttributeID
Next intIndex

' Display the Conditions
varConditions = objEventServer.QueryConditionNames(intCatID)
lstConditionNames.Clear
For intIndex = LBound(varConditions) To UBound(varConditions)
    lstConditionNames.AddItem varConditions(intIndex)
Next intIndex
lstConditionNames.ListIndex = 0
subAddSubConditionNames (lstConditionNames.Text)

End Sub

Private Sub subSetEventAttributes(intCatID As Integer)

Dim intIndex As Integer
Dim intAttributeCount As Integer
Dim aintAttributeIDs() As Integer
Dim varAttributeIDs As Variant

ReDim aintAttributeIDs(lstAttributes.ListCount)
intAttributeCount = 0

For intIndex = 0 To lstAttributes.ListCount - 1
    If lstAttributes.Selected(intIndex) Then
        aintAttributeIDs(intAttributeCount) = lstAttributes.ItemData(intIndex)
        intAttributeCount = intAttributeCount + 1
    End If
Next intIndex

ReDim Preserve aintAttributeIDs(intAttributeCount)
varAttributeIDs = aintAttributeIDs
objSubscription1.SelectReturnAttributes intCatID, varAttributeIDs

End Sub

Private Sub subAddSubConditionNames(strConditionName As String)

Dim varSubConditions As Variant
Dim intLoopIndex As Integer

lstSubConditionNames.Clear
varSubConditions = objEventServer.QuerySubConditionNames(strConditionName)

For intLoopIndex = LBound(varSubConditions) To UBound(varSubConditions)
    lstSubConditionNames.AddItem varSubConditions(intLoopIndex)
Next intLoopIndex
End Sub

Private Sub subServerConnect()
    Dim varServer As Variant
    
 '   If txtServerName.Text <> cTxtLocalServerText _
 '       And txtServerName.Text <> "" Then
            varServer = txtServerNode.Text
            objEventServer.Connect cboProgIDs.Text, _
                varServer
 '   Else
 '           objEventServer.Connect cboProgIDs.Text
 '   End If

subBrowseCategories

    cmdConnectServer.Enabled = False
    cmdDisconnectServer.Enabled = True
    cmdServerProperties.Enabled = True
    cmdSubscriptionDefaults.Enabled = True
    txtServerNode.Enabled = False
    cboProgIDs.Enabled = False
    chkSubscription1.Enabled = True
    fraCategories.Visible = True
End Sub

Private Sub subServerDisconnect()
  
    cmdConnectServer.Enabled = True
    cmdDisconnectServer.Enabled = False
    cmdServerProperties.Enabled = False
    cmdSubscriptionDefaults.Enabled = True
    txtServerNode.Enabled = True
    cboProgIDs.Enabled = True
    chkSubscription1.Value = False
    chkSubscription1.Enabled = False
    fraSubscription1.Visible = False
    fraCategories.Visible = False

    objEventServer.OPCEventSubscriptions.RemoveAll
    objEventServer.Disconnect
End Sub
