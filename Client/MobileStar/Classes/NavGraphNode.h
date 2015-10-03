#pragma once
#include "GraphNode.h"
#include "cocos2d.h"
#include "Thing.h"

class NavGraphNode : public GraphNode{
public:
    //노드의 상태
    enum class NodeState{
        Empty,          //빈 지형 : 움직일 수 있는 지형
        StaticTile,     //이동할 수 없는 지형
        Static,         //정적 유닛 : 건물, 미네랄 등
        Dynamic,        //동적 유닛 : 움직이는 유닛
    };
    
protected:
    NodeState m_State;
    
    Thing* m_underThing;
    Thing* m_onThing;
    Thing* m_overThing;
    
    
    //노드의 위치
    cocos2d::Vec2 m_vPosition;
public:
    NavGraphNode()
    : m_State(NodeState::Empty)
    {
        m_underThing = NULL;
        m_onThing = NULL;
        m_overThing = NULL;
    }
    
    cocos2d::Vec2 getPosition()const{return m_vPosition;}
    void setPosition(cocos2d::Vec2 pos){m_vPosition = pos;}
    
    void SetEmpty(){ m_State = NodeState::Empty; }
    void SetStaticTile(){ m_State = NodeState::StaticTile; }
    void SetStatic(){ m_State = NodeState::Static; }
    void SetDynamic(){ m_State = NodeState::Dynamic; }
    
    bool IsEmpty()const{return m_State == NodeState::Empty;}
    bool IsStaticTile()const{return m_State == NodeState::StaticTile;}
    bool IsStatic()const{return m_State == NodeState::Static;}
    bool IsDynamic()const{return m_State == NodeState::Dynamic;}
    
    NodeState GetState()const{ return m_State; }
    
    
    void SetUnderThing(Thing* thing){ m_underThing = thing; }
    void SetOnThing(Thing* thing){ m_onThing = thing; }
    void SetOverThing(Thing* thing){ m_overThing = thing; }
    
    bool isEmptyThing(int zPosition)
    {
        switch (zPosition) {
            case Z_POSITION_UNDER:
            {
                if(m_underThing == NULL) return true;
                else return false;
            }
                break;
            
            case Z_POSITION_ON:
            {
                if(m_onThing == NULL) return true;
                else return false;
            }
                break;
            
            case Z_POSITION_OVER:
            {
                if(m_overThing == NULL) return true;
                else return false;
            }
                break;
                
            default:
                return false;
        }
    }
};