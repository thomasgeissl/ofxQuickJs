#pragma once
#include "./js.h"
namespace ofxQuick
{
    class gameObject
    {
    public:
        void setup(std::string path, bool liveReload = true)
        {
            _js.setup(path, liveReload);
            ofAddListener(ofEvents().update, this, &ofxQuick::gameObject::onUpdate, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().draw, this, &ofxQuick::gameObject::onDraw, OF_EVENT_ORDER_BEFORE_APP);
            ofAddListener(ofEvents().exit, this, &ofxQuick::gameObject::onExit, OF_EVENT_ORDER_BEFORE_APP);
            ofAddListener(ofEvents().keyPressed, this, &ofxQuick::gameObject::onKeyPressed, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().keyReleased, this, &ofxQuick::gameObject::onKeyReleased, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mouseMoved, this, &ofxQuick::gameObject::onMouseMoved, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mouseDragged, this, &ofxQuick::gameObject::onMouseDragged, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mousePressed, this, &ofxQuick::gameObject::onMousePressed, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mouseEntered, this, &ofxQuick::gameObject::onMouseEntered, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mouseExited, this, &ofxQuick::gameObject::onMouseExited, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().mouseReleased, this, &ofxQuick::gameObject::onMouseReleased, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().windowResized, this, &ofxQuick::gameObject::onWindowResized, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().fileDragEvent, this, &ofxQuick::gameObject::onDragEvent, OF_EVENT_ORDER_AFTER_APP);
            ofAddListener(ofEvents().messageEvent, this, &ofxQuick::gameObject::onMessageEvent, OF_EVENT_ORDER_AFTER_APP);
            _js.call("setup");
        }
        void onUpdate(ofEventArgs &e)
        {
            _js.call("update");
        }
        void onDraw(ofEventArgs &e)
        {
            _js.call("draw");
        }
        void onExit(ofEventArgs &e)
        {
            _js.call("exit");
        }

        void onKeyPressed(ofKeyEventArgs &e)
        {
            std::string s(1, e.key);
            _js.call("keyPressed", {JS_NewString(_js.getContext(), s.c_str())});
        }
        void onKeyReleased(ofKeyEventArgs &e)
        {
            std::string s(1, e.key);
            _js.call("keyReleased", {JS_NewString(_js.getContext(), s.c_str())});
        }

        void onMouseMoved(ofMouseEventArgs &e)
        {
            _js.call("mouseMoved", {JS_NewInt32(_js.getContext(), e.x),
                                    JS_NewInt32(_js.getContext(), e.y)});
        }
        void onMouseDragged(ofMouseEventArgs &e)
        {
            _js.call("mouseDragged", {JS_NewInt32(_js.getContext(), e.x),
                                      JS_NewInt32(_js.getContext(), e.y)});
        }
        void onMousePressed(ofMouseEventArgs &e)
        {
            _js.call("mousePressed", {JS_NewInt32(_js.getContext(), e.x),
                                      JS_NewInt32(_js.getContext(), e.y),
                                      JS_NewInt32(_js.getContext(), e.button)});
        }
        void onMouseReleased(ofMouseEventArgs &e)
        {
            _js.call("mouseReleased", {JS_NewInt32(_js.getContext(), e.x),
                                       JS_NewInt32(_js.getContext(), e.y),
                                       JS_NewInt32(_js.getContext(), e.button)});
        }
        void onMouseEntered(ofMouseEventArgs &e)
        {
            _js.call("mouseEntered", {JS_NewInt32(_js.getContext(), e.x),
                                      JS_NewInt32(_js.getContext(), e.y)});
        }
        void onMouseExited(ofMouseEventArgs &e)
        {
            _js.call("mouseExited", {JS_NewInt32(_js.getContext(), e.x),
                                     JS_NewInt32(_js.getContext(), e.y)});
        }
        void onWindowResized(ofResizeEventArgs &e)
        {
            _js.call("windowResized", {
                                          JS_NewInt32(_js.getContext(), e.width),
                                          JS_NewInt32(_js.getContext(), e.height),
                                      });
        }
        void onDragEvent(ofDragInfo &e)
        {
            ofLogNotice() << "TODO: dragInfo >> js world";
            // _js.call("dragEvent", {
            //                           JS_NewInt32(_js.getContext(), e.width),
            //                           JS_NewInt32(_js.getContext(), e.height),
            //                       });
        }
        void onMessageEvent(ofMessage &e)
        {
            ofLogNotice() << "TODO: message event >> js world";
            // _js.call("dragEvent", {
            //                           JS_NewInt32(_js.getContext(), e.width),
            //                           JS_NewInt32(_js.getContext(), e.height),
            //                       });
        }

    protected:
        ofxQuick::js _js;
    };
};